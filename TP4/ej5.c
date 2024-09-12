#include <stdio.h>

int main() {
    // Inicializar una cadena con una palabra cualquiera
    char palabra[] = "Adriana";

    // Obtener la dirección de la primera letra de la cadena
    char *primeraLetra = &palabra[0];

    // Mostrar la dirección de la primera letra
    printf("La direccion de la primera letra es: %p\n", (void*)primeraLetra); //ANTES
    printf("La direccion de la primera letra es: %p\n", palabra); //AHORA
    // Dirección de la tercera letra
    char *terceraLetra = &palabra[2];
    printf("La direccion de la tercera letra es: %p\n", (void*)terceraLetra);//ANTES
    printf("La direccion de la tercera letra es: %p\n", palabra+2);//AHORA
    printf("La direccion de la tercera letra es: %p\n", (void*)(palabra+2));
    // Bucle para dar tres oportunidades al usuario
    void *direccionUsuario;
    int intentos = 3;
    while (intentos > 0) {
        printf("Introduce la direccion de la tercera letra (intento %d): ", 4 - intentos);
        scanf("%p", &direccionUsuario);

        if (direccionUsuario == (void*)terceraLetra) {
            printf("¡Correcto! La direccion es: %p\n", direccionUsuario);
            return 0;
        } else {
            printf("Incorrecto. ");
            intentos--;
        }
    }

    // Mensaje indicando la dirección correcta después de tres intentos fallidos
    printf("Lo siento, has agotado los intentos. La direccion correcta es: %p\n", (void*)terceraLetra);

    return 0;
}