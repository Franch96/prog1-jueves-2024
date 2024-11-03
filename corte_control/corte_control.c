#include <stdio.h>
#include <stdlib.h>

// Generar un reporte que muestre los totales por sucursal y por tipo de factura

void corte_control(){
    FILE * fp = fopen("facturas.txt", "r");
    if(fp == NULL) {
        printf("Error al abrir el archivo");
    } else {
        int total_sucursal, total_tipo;
        char tipo_actual, tipo;
        int sucursal_actual, sucursal, importe;
        printf("-----Reporte de totales por SUCURSAL y por TIPO de factura------\n");
        printf("Sucursal\tTipo\tImporte\n");
        fscanf(fp, "%d,%c,%d", &sucursal, &tipo, &importe);
        while(!feof(fp)) {
            sucursal_actual = sucursal;
            total_sucursal = 0;
            while(!feof(fp) && sucursal_actual == sucursal) {
                tipo_actual = tipo;
                total_tipo = 0;
                while(!feof(fp) && sucursal_actual == sucursal && tipo_actual == tipo) {
                    total_tipo += importe;
                    printf("%d %c %d\n", sucursal, tipo, importe);
                    fscanf(fp, "%d,%c,%d", &sucursal, &tipo, &importe);
                }
                printf("Total factura tipo %c en sucursal %d: %d \n", tipo_actual, sucursal_actual, total_tipo);
                total_sucursal += total_tipo;
            }
            printf("Total en sucursal %d: %d\n\n", sucursal_actual, total_sucursal);
        }
        
    }

    fclose(fp);
}

int main()
{
    corte_control();
    return 0;
}
