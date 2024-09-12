#include <stdio.h>

int main() {
    // a) Declarar las variables enteras largas value1 y value2, e inicializar value1 a 200000
    long value1 = 200000;
    long value2;

    // b) Declarar la variable Ptr como apuntador a un tipo long
    long *Ptr;

    // c) Asignar la dirección de la variable value1 a la variable de apuntador Ptr
    Ptr = &value1;

    // d) Imprima el valor al que apunta Ptr
    printf("El valor al que apunta Ptr: %ld\n", *Ptr);

    // e) Asignar a la variable value2 el valor al que apunta Ptr
    value2 = *Ptr;

    // f) Imprima el valor de value2
    printf("El valor de value2: %ld\n", value2);

    // g) Imprima la dirección de value1
    printf("La dirección de value1: %p\n", (void*)&value1);

    // h) Imprima la dirección almacenada en Ptr. ¿Es igual el valor impreso que la dirección de value1?
    printf("La dirección almacenada en Ptr: %p\n", (void*)Ptr);

    printf("La direccion de value2: %p\n", (void*)&value2);
    return 0;
}