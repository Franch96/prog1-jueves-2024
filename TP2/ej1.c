// Crear una función con cuatro parámetros (v, N, menor, mayor) 
// que cargue un vector v de longitud N  con números enteros aleatorios comprendidos entre menor  y mayor.  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int crear_numeros_aleatorios(int menor, int mayor){
    int numero = (rand()% (mayor - menor)+1) + menor;
    return numero;   
}

void cargar_vector(int* v,int n, int menor,int mayor){

    for (int i = 0;i<n;i++){
        v[i] = crear_numeros_aleatorios(menor,mayor);
    }
    
}

int mayor_numero(int* v, int cantidad_elementos){
    int mayor = v[0];
    for (int i=1;i<cantidad_elementos;i++){
        if (v[i] > mayor){
            mayor = v[i];
        }
    }
    return mayor;
}

int mayor_posicion(int* v, int cantidad_elementos){
    int mayor = v[0];
    int pos = 0;
    for (int i=1;i<cantidad_elementos;i++){
        if (v[i] >= mayor){
            mayor = v[i];
            pos = i;
        }
    }
    return pos;
}

void test_mayor(){
    int vector[] = {5,9,4,8,3};
    int n = 5;
    assert(9 ==  mayor_numero(vector,n));
    assert(1 == mayor_posicion(vector,n));
    printf("PASO\n");
}

int main(){

    srand(time(NULL));
    int menor ,mayor;
    menor = 5;
    mayor = 10;
    int n =5;
    int vector[n] ;
    cargar_vector(vector,n,menor,mayor);
    
    for (int i=0;i<10;i++){
        printf("el vector en la posicion %d es %d \n", i,vector[i]);   
    }
    int numero_mayor = mayor_numero(vector,n);
    printf("El mayor valor del vector es: %d \n", numero_mayor);
    int mayor_pos = mayor_posicion(vector,n);

    printf("%d en la pos:%d\n",numero_mayor == vector[mayor_pos],mayor_pos);
    
    test_mayor();



    return 0;
}
// Realizar un programa que reciba un vector con n elementos numéricos y 
// muestre por pantalla el mayor de los valores del vector.
//  Haga una función auxiliar que pruebe la correctitud del programa.