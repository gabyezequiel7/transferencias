FILE=./executable
if [ -f "$FILE" ]; then
    rm "$FILE"
fi
gcc -o executable procesar_transferencias.c main.c guardar_saldo.c guardar_transferencias.c validar_archivos.c estado_cuenta.c
./executable $1
rm "$FILE"
