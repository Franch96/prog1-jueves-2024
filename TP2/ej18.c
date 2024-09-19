// Haga una función que reciba dos arreglos ordenados A(n) y B(m), y 
// retorne un nuevo arreglo C que contenga los elementos de A y de B de 
// tal forma que quede también ordenado. Si existen elementos repetidos en 
// los arreglos originales, 
// en C deberán aparecer solamente una vez

#include <stdio.h>

int arreglos_ordenados(int v1[], int v2[], int v3[], int n1, int n2) {
    int i1 = 0, i2 = 0, i3 = 0;
    while(i1 < n1 && i2 < n2) {
        if(v1[i1] < v2[i2]) {
            if(i3 == 0 || v3[i3 - 1] != v1[i1]) {
                v3[i3] = v1[i1];
                i3++;
            }
            i1++;
        }
        else if(v1[i1] > v2[i2]) {
            if(i3 == 0 || v3[i3 - 1] != v2[i2]) {
                v3[i3] = v2[i2];
                i3++;
            }
            i2++;
        }
        else {
            if(i3 == 0 || v3[i3 - 1] != v2[i2]) {
                v3[i3] = v2[i2];
                i3++;
            }
            i1++;
            i2++;
        }
    }
    while(i1 < n1) {
        if(v3[i3 - 1] != v1[i1]) {
            v3[i3] = v1[i1];
            i3++;
        }
        i1++;
    }
    while(i2 < n2) {
        if(v3[i3 - 1] != v2[i2]) {
            v3[i3] = v2[i2];
            i3++;
        }
        i2++;
    }
    return i3;
}

void mostrar(int v[], int n){
    int i=0;
    for (i ; i < n ; i++){
        printf("%d ", v[i]);
    }
}

int main()
{
    int v1[] = {1, 2, 3, 3, 10, 18};         
    int v2[] = {3, 4, 8, 9};
    int n1 = 6;
    int n2 = 4;
    int v3[n1 + n2];
    int n3 = arreglos_ordenados(v1, v2, v3, n1, n2);
    mostrar(v3, n3);
    return 0;
}
