#include "main.h"

int procesarTransferencias() {
  FILE *transferenciasFirst, *transferenciasSecond, *transferenciasThird, *trasnferenciasMerge;
  FILE *cuentasFirstBank, *cuentasActualizadas, *estadoDeTransacciones;
  transferenciasFirst = fopen(PATH_FILE_FIRST_BANK, "rb");
  transferenciasSecond = fopen(PATH_FILE_SECOND_BANK, "rb");
  transferenciasThird = fopen(PATH_FILE_THIRD_BANK, "rb");
  trasnferenciasMerge = fopen(PATH_FILE_MERGE_TRANSFER, "a+");
  cuentasFirstBank = fopen(PATH_FILE_ACCOUNTS, "rb");
  cuentasActualizadas = fopen(PATH_FILE_ACCOUNTS_UPDATE, "w");
  estadoDeTransacciones = fopen(PATH_FILE_STATUS_TRANSACTIONS, "w");

  mergeTransacciones(transferenciasFirst, trasnferenciasMerge);
  mergeTransacciones(transferenciasSecond, trasnferenciasMerge);
  mergeTransacciones(transferenciasThird, trasnferenciasMerge);

  fclose(transferenciasFirst);
  fclose(transferenciasSecond);
  fclose(transferenciasThird);
  fclose(trasnferenciasMerge);

  actualizarSaldo(cuentasFirstBank, cuentasActualizadas, estadoDeTransacciones);

  fclose(cuentasActualizadas);
  fclose(estadoDeTransacciones);
  return 1;
}

int mergeTransacciones(FILE *file, FILE *merge) {
  Transferencia_t buffer;
  fread(&buffer, sizeof(Transferencia_t), 1, file);
  while(!feof(file)) {
    fwrite(&buffer, sizeof(Transferencia_t), 1, merge);
    fread(&buffer, sizeof(Transferencia_t), 1, file);
  }
  fread(&buffer, sizeof(Transferencia_t), 1, file);
  return 1;
}

int actualizarSaldo(FILE *cuentas, FILE *cuentasActualizadas, FILE *estadoDeTransacciones) {
  Cuenta_t cuenta;
  fread(&cuenta, sizeof(Cuenta_t), 1, cuentas);
  while(!feof(cuentas)) {
    char liniecita[151] = "*";
    for (int i = 0; i < 150; i++) {
      strcat(liniecita, "*");
    }
    printf("%s\n\n", liniecita);
    Transferencia_t transferencia;
    FILE *merge = fopen(PATH_FILE_MERGE_TRANSFER, "r");
    fread(&transferencia, sizeof(Transferencia_t), 1, merge);
    printf("%s\n\n", cuenta.alias);
    printf("SALDO INICIAL: %f\n\n\n", cuenta.saldo);
    while(!feof(merge)) {
      if (strcmp(cuenta.alias, transferencia.cuenta_origen) == 0) {
        float totalSaldo = cuenta.saldo - transferencia.monto;
        if (totalSaldo < 0) {
          actualizarEstadoTransacciones(transferencia, estadoDeTransacciones, 0, cuenta.saldo);
          fread(&transferencia, sizeof(Transferencia_t), 1, merge);
          continue;
        }
        cuenta.saldo = totalSaldo;
        actualizarEstadoTransacciones(transferencia, estadoDeTransacciones, 1, cuenta.saldo);
      }
      if (strcmp(cuenta.alias, transferencia.cuenta_dest) == 0) {
        cuenta.saldo += transferencia.monto;
        actualizarEstadoTransacciones(transferencia, estadoDeTransacciones, 1, cuenta.saldo);
      }
      fread(&transferencia, sizeof(Transferencia_t), 1, merge);
    }
    fclose(merge);
    guardarCuentasActualizadas(cuenta, cuentasActualizadas);
    printf("SALDO FINAL: %f\n\n", cuenta.saldo);
    fread(&cuenta, sizeof(Cuenta_t), 1, cuentas);
  }
  return 0;
}

void guardarCuentasActualizadas(Cuenta_t cuentaActualizada, FILE *cuentasActualizadas) {
  char saldo[5];
  char estadoCuenta[255];
  fflush(stdout);

  strcpy(estadoCuenta, cuentaActualizada.alias);
  gcvt(cuentaActualizada.saldo, 5, saldo);
  strcat(estadoCuenta, "\t monto: ");
  strcat(estadoCuenta, saldo);
  strcat(estadoCuenta, "\n\n");
  printf("%s\n", estadoCuenta);
  fwrite(estadoCuenta, sizeof(Cuenta_t), 1, cuentasActualizadas);
  return;
}

void actualizarEstadoTransacciones(Transferencia_t transferencia, FILE *estadoDeTransacciones, int estadoTran, float saldoRec) {
  char estadoTransaccion[255];
  strcpy(estadoTransaccion, transferencia.cuenta_origen);
  char estado[8];
  char saldo[10], monto[10];
  sprintf (monto, "%f", transferencia.monto);
  sprintf (saldo, "%f", saldoRec);
  strcpy(estado, (estadoTran == 1 ? "TRUE" : "FALSE"));
  strcat(estadoTransaccion, "\t BANCO ORIGEN: ");
  strcat(estadoTransaccion, transferencia.banco_origen);
  strcat(estadoTransaccion, "\t CUENTA DESTINO: ");
  strcat(estadoTransaccion, transferencia.cuenta_dest);
  strcat(estadoTransaccion, "\t BANCO DESTINO: ");
  strcat(estadoTransaccion, transferencia.cuenta_dest);
  strcat(estadoTransaccion, "\t MONTO: ");
  strcat(estadoTransaccion, monto);
  strcat(estadoTransaccion, "\t ESTADO: ");
  strcat(estadoTransaccion, estado);
  // strcat(estadoTransaccion, "\n TOTAL: ");
  // strcat(estadoTransaccion, saldo);
  strcat(estadoTransaccion, "\n");
  printf("%s\n", estadoTransaccion);
  fwrite(estadoTransaccion, sizeof(Transferencia_t), 1, estadoDeTransacciones);
  return;
}
