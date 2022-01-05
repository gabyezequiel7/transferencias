#include "main.h"

void estadoDeCuentas() {
  FILE *cuentasFirstBank;
  Cuenta_t cuenta;
  cuentasFirstBank = fopen(PATH_FILE_ACCOUNTS, "rb");
  fread(&cuenta, sizeof(Cuenta_t), 1, cuentasFirstBank);
  char estadoCuenta[1024] = "";
  while(!feof(cuentasFirstBank)) {
    char saldo[10];
    fflush(stdout);
    printf("%s\t SALDO: %f\n\n", cuenta.alias, cuenta.saldo);
    fread(&cuenta, sizeof(Cuenta_t), 1, cuentasFirstBank);
  }
  return;
}
