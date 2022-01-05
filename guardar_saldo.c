#include "main.h"

int guardarSaldo() {
  Cuenta_t cuentasFirstBank[4] = {
    {"HALCON.ALTO", 15.2},
    {"COLIBRI.VERDE", 17.2},
    {"LEON.DORADO", 77.5},
    {"TIGRE.PLATEADO", 100.1}
  };

  FILE *cuentas;
  cuentas = fopen(PATH_FILE_ACCOUNTS, "wb");
  if (cuentas == 0) {
    printf("FALLO");
    return 1;
  }
  fwrite(cuentasFirstBank, sizeof(Cuenta_t), 4, cuentas);
  fclose(cuentas);
  return 0;
}
