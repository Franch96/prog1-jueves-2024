#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 3
#define COLUMNAS 3

// Leer una matriz de tres filas por tres columnas y calcular 
// la suma de cada una de sus filas y de sus columnas, colocando 
// los resultados en dos vectores, uno para la suma de las filas y 
// otro para la suma de las columnas. 

void cargar_matriz_aleatoria(int matriz[FILAS][COLUMNAS]) {
    for(int f = 0; f < FILAS; f++) {
        for(int c = 0; c < COLUMNAS; c++) {
            matriz[f][c] = rand() % 10; 
        }
    }
}

void mostrar_matriz(int matriz[FILAS][COLUMNAS]) {
    for(int f = 0; f < FILAS; f++) {
        for(int c = 0; c < COLUMNAS; c++) {
            printf("%d\t", matriz[f][c]);
        }
        printf("\n");
    }
}

void suma_filas_columnas(int matriz[FILAS][COLUMNAS], int filas[], int columnas[]) {
    for(int f = 0; f < FILAS; f++) {
        for(int c = 0; c < COLUMNAS; c++) {
            columnas[c] += matriz[f][c];
            filas[f] += matriz[f][c];
        }
    }
}

void mostrar_vector(int v[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i + 1, v[i]);
    }    
}

int main()
{
    int m[FILAS][COLUMNAS] = {0};
    cargar_matriz_aleatoria(m);
    mostrar_matriz(m);
    int filas[] = {0, 0, 0};
    int columnas[] = {0, 0, 0};
    suma_filas_columnas(m, filas, columnas);
    mostrar_vector(columnas, 3);
}
