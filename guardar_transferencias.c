#include "main.h"

int guardarTransferencias() {
  Transferencia_t transferenciasFirstBank[TAMANIO_FIRST_BANK] = {
    {"HALCON.ALTO", "FIRST BANK", "ALOE.GRIS", "SECOND BANK", 5},
    {"HALCON.ALTO", "FIRST BANK", "CUARZO.ROJO", "THIRD BANK", 50},
    {"COLIBRI.VERDE", "FIRST BANK", "CACTUS.GRIS", "SECOND BANK", 9},
    {"TIGRE.PLATEADO", "FIRST BANK", "ALOE.GRIS", "SECOND BANK", 7}
  };
  Transferencia_t transferenciasSecondBank[TAMANIO_SECOND_BANK] = {
    {"ALOE.GRIS", "SECOND BANK", "HALCON.ALTO", "FIRST BANK", 3},
    {"CACTUS.GRIS", "SECOND BANK", "COLIBRI.VERDE", "FIRST BANK", 1},
    {"ALOE.GRIS", "SECOND BANK", "TIGRE.PLATEADO", "FIRST BANK", 3},
    {"BONSAI.VERDE", "SECOND BANK", "LEON.DORADO", "FIRST BANK", 15},
  };
  Transferencia_t transferenciasThirdBank[TAMANIO_THIRD_BANK] = {
    {"CUARZO.ROJO", "THIRD BANK", "HALCON.ALTO", "FIRST BANK", 8},
    {"MARMOL.AZUL", "THIRD BANK", "COLIBRI.VERDE", "FIRST BANK", 5}
  };

  FILE *transferenciasFirst = fopen("transferenciasFirstBank.dat", "wb");
  fwrite(transferenciasFirstBank, sizeof(Transferencia_t), TAMANIO_FIRST_BANK, transferenciasFirst);
  fclose(transferenciasFirst);

  FILE *transferenciasSecond = fopen("transferenciasSecondBank.dat", "wb");
  fwrite(transferenciasSecondBank, sizeof(Transferencia_t), TAMANIO_SECOND_BANK, transferenciasSecond);
  fclose(transferenciasSecond);

  FILE *transferenciasThird = fopen("transferenciasThirdBank.dat", "wb");
  fwrite(transferenciasThirdBank, sizeof(Transferencia_t), TAMANIO_THIRD_BANK, transferenciasThird);
  fclose(transferenciasThird);
  return 0;
}
