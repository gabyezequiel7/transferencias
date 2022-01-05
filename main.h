#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO_FIRST_BANK 5
#define TAMANIO_SECOND_BANK 5
#define TAMANIO_THIRD_BANK 2
#define CANT_USERS 4
#define PATH_FILE_FIRST_BANK "./transferenciasFirstBank.dat"
#define PATH_FILE_SECOND_BANK "./transferenciasSecondBank.dat"
#define PATH_FILE_THIRD_BANK "./transferenciasThirdBank.dat"
#define PATH_FILE_MERGE_TRANSFER "./transferenciasMerge.txt"
#define PATH_FILE_ACCOUNTS "./cuentas.dat"
#define PATH_FILE_ACCOUNTS_UPDATE "./cuentasActualizadas.txt"
#define PATH_FILE_STATUS_TRANSACTIONS "./estadoDeTransacciones.txt"

struct Cuenta{
  char alias[16];
  float saldo;
};

typedef struct Cuenta Cuenta_t;

typedef struct Transferencia {
  char cuenta_origen[16];
  char banco_origen[16];
  char cuenta_dest[16];
  char banco_dest[16];
  float monto;
} Transferencia_t;


int guardarSaldo();
int guardarTransferencias();
int procesarTransferencias();
int procesarTransferencias();
int validarArchivos();
int mergeTransacciones(FILE *file, FILE *merge);
int actualizarSaldo(FILE *cuentas, FILE *cuentasActualizadas, FILE *estadoDeTransacciones);
void guardarCuentasActualizadas(Cuenta_t cuentaActualizada, FILE *cuentasActualizadas);
void actualizarEstadoTransacciones(Transferencia_t transferencia, FILE *estadoDeTransacciones, int estadoTran, float saldoRec);
void estadoDeCuentas();
