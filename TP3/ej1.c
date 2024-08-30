// imports
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


const int N = 20;

void ordenar_burbuja(int datos[], int n) {
    int i, j, aux;
        for(i=0;i<n;i++)
            for (j = 1; j <n - i; j++){
                if (datos[j-1] > datos[j]) {
                    /* Intercambio */
                    aux = datos[j];
                    datos[j] = datos[j-1];
                    datos[j-1] = aux;
                }
            }
}

void ordenar_burbuja_d(int datos[],int n){
    int i, j, aux;
        for(i=0;i<n;i++)
            for (j = 1; j <n - i; j++){
                if (datos[j-1] < datos[j]) {
                    /* Intercambio */
                    aux = datos[j];
                    datos[j] = datos[j-1];
                    datos[j-1] = aux;
                }
            }    
}

int main(){

    int datos[] ={5,3,2,9,7,8,5,7,9,3,10,5,3,2,8,1,4,9,6,10};
    ordenar_burbuja_d(datos, N);
    for (int i = 1; i < N; i++){
        assert(datos[i] <= datos[i - 1]);
        printf("el elemento i %d es %d \n",i,datos[i]);
    }
    printf("paso ordenar burbuja mejorado\n");
}
