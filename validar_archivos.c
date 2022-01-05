#include "main.h"

int validarArchivos() {
  FILE *transferenciasFirst, *transferenciasSecond, *transferenciasThird, *cuentasFirstBank;
  cuentasFirstBank = fopen(PATH_FILE_ACCOUNTS, "rb");
  transferenciasFirst = fopen(PATH_FILE_FIRST_BANK, "rb");
  transferenciasSecond = fopen(PATH_FILE_SECOND_BANK, "rb");
  transferenciasThird = fopen(PATH_FILE_THIRD_BANK, "rb");
  if (cuentasFirstBank == NULL) {
    return 0;
  }
  if (transferenciasFirst == NULL) {
    return 0;
  }
  if (transferenciasSecond == NULL) {
    return 0;
  }
  if (transferenciasThird == NULL) {
    return 0;
  }
  return 1;
}
