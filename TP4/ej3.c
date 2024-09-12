#include <stdio.h>

int main() {
    int n;
    float numeros[100];
    
    // Pedir al usuario la cantidad de números a ingresar
    do {
        printf("Introduce el número de elementos (menos de 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);
    
    // Leer los números y almacenarlos en el arreglo usando punteros
    float *ptr = numeros;
    printf("Introduce %d números reales:\n", n);
    for (float *p = ptr; p < ptr + n; p++) {
        scanf("%f", p);
    }

    // Mostrar los números en orden inverso usando aritmética de punteros
    printf("Números en orden inverso:\n");
    for (float *p = ptr + n - 1; p >= ptr; p--) {
        printf("%.2f\n", *p);
    }

    return 0;
}