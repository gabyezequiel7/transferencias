#include "main.h"

int main(int argc, char *argv[]) {
  if (argv[1] == NULL ) {
    printf("\nES NECESARIO PASAR PARAMETROS\n\n");
    printf("'init'\t INICIALIZA LOS ARCHIVOS NECESARIOS\n'accounts'\t LISTA LAS CUENTAS CREADAS\n");
    return 0;
  }
  if (strcmp(argv[1], "init") == 0) {
    int estadoBorrarCuentasActualizadas = remove(PATH_FILE_ACCOUNTS_UPDATE);
    int estadoBorrarEstadoTransacciones = remove(PATH_FILE_STATUS_TRANSACTIONS);
    int estadoBorrarCuentas = remove(PATH_FILE_ACCOUNTS);

    guardarSaldo();
    guardarTransferencias();
    printf("SE HAN CREADOS LOS ARCHIVOS DE CUENTAS Y TRANSACCIONES\n");
    printf("PARA PROCESAR LAS TRANSACCIONES PASE COMO PARAMETRO 'process'\n");
    return 0;
  }
  if (strcmp(argv[1], "accounts") == 0) {
    estadoDeCuentas();
    printf("\nPARA PROCESAR LAS TRANSACCIONES PASE COMO PARAMETRO 'process'\n");
    return 0;
  }
  if (strcmp(argv[1], "process") != 0) {
    printf("PARAMETROS NO VALIDOS\n");
    return 0;
  }
  int estadoBorrarMergeTransacciones = remove(PATH_FILE_MERGE_TRANSFER);
  int valid = validarArchivos();
  if (valid == 0) {
    printf("DEBE GENERAR LOS ARCHIVOS DE TRANSFERENCIA Y CUENTAS\nINICIALIZA LOS ARCHIVOS NECESARIOS CON PARAMETRO 'init'\n");
    return 1;
  }
  procesarTransferencias();
  return 0;
}
