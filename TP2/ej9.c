// imports
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Escribir una función que acepte como parámetro un vector que contiene números positivos, 
// que puede contener valores duplicados, y reemplace cada elemento repetido por -1 (menos uno). 
//  El procedimiento debe retornar el vector modificado y la cantidad de veces que fue modificado.  


int modificar_duplicados(int n,int vector[]){
    int contador = 0;
    for(int i = 0; i < n; i++){
        for (int j = i+1;j < n ;j++ ){
            if (vector[i] == vector[j]){
                vector[i] = -1;
                contador++;
            }
        }
    }
    return contador;
}


int main(){
    int n = 8;
    int arreglo[] = {3,1,5,3,1,7,5,3};
    modificar_duplicados(n,arreglo);
    for (int i=0;i<n;i++){
        printf("Elemento i %d, es %d \n",i,arreglo[i]);
    }
    return 0;
}
