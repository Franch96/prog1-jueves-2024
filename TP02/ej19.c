#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Realizar un programa que permita, a través de una función actualizar un arreglo ordenado 
//  de n elementos. Esta función recibe cuatro parámetros : el arreglo a actualizar, 
//  la cantidad de elementos, la acción a realizar que puede ser I, B o A  y  un valor entero. 
//  Si la acción es I deberá ingresar un nuevo valor en la posición que indique valor. 
//  Si es B deberá encontrar el valor dentro del arreglo y borrarlo
//  (si no lo encuentra devolver mensaje de error)
//   y si es A deberá agregar el valor en la última posición.
#define N = 10

// TODO pasar elementos utiles por referencia
int* agregar_al_final(int vector[],int* elementos_utiles, int valor_a_agregar,int tamaño_vector){
    if (*elementos_utiles < tamaño_vector){
        vector[*elementos_utiles]=valor_a_agregar;
        (*elementos_utiles)++;
        // *elementos_utiles+=1;
        // *elementos_utiles = *elementos_utiles+1 ; 
    }
    return elementos_utiles;
}

// void actualizar_vector(int vector[],int elementos_utiles, int valor_a_agregar,int tamaño_vector, char accion){

//     if(accion == 'a'){
//         agregar_al_final(vector,elementos_utiles,valor_a_agregar, tamaño_vector);
//     }
// }


int main(){
    int vector[] = {2,3,4,5};
    int elementos_utiles = 4;
    int tamaño_vector = 10;
    int valor = 8;
    int aux;
    aux = agregar_al_final(vector,&elementos_utiles,valor,tamaño_vector);

    printf("el valor de elementos utiles es: %p \n",&elementos_utiles);
    printf("el valor de aux es: %p \n",aux);
    // (*aux)++;
    // printf("el valor de elementos utiles es: %i \n",elementos_utiles);
    // printf("el valor de aux es: %i \n",*aux);

    for (int i=0; i<elementos_utiles;i++){
        printf("En la ubicacion %i, esta el valor %i \n",i,vector[i]);
    }

}



