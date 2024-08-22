#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Escribir una función que reciba tres cadenas de caracteres y 
// muestre por pantalla el resultado de concatenar las tres 
// primeras letras de las cadenas. Además, la función deberá 
// retornar un cero si las dos primeras cadenas son iguales, 
// un dos si las últimas dos cadenas son iguales, un tres si 
// todas las cadenas son iguales, y un cuatro si todas las cadenas fueran distintas.

int comparar(char c1[], char c2[]) {
    int cant1, cant2;
    int flag = 1;
    cant1 = strlen(c1);
    cant2 = strlen(c2);
    if(cant1 == cant2) {
        for(int i = 0; i < cant1; i++) {
            if(c1[i] != c2[i]) {
                flag = 0;
            }
        }
    }
    else {
        flag = 0;
    }
    return flag;
}

int concatenar(char c1[], char c2[], char c3[]) {
    char resultado[5];
    int res = 4;
    resultado[0] = c1[0];
    resultado[1] = c2[0];
    resultado[2] = c3[0];
    printf("%s", resultado);
    if(comparar(c1, c2)) {
        res = 0;
    }
    if(comparar(c2, c3)) {
        res = 2;
    }
    if(comparar(c1, c2) && comparar(c1, c3)) {
        res = 3;
    }
    return res;
}

int main()
{
    char c1[10] = "Hola";
    char c2[10] = "Chau";
    char c3[10] = "Mundo";
    printf("\n%d", concatenar(c1, c2, c3));
    return 0;
}
