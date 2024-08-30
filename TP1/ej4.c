#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contar_letras(char palabra[]) {
    int letras = 0;
    int i = 0;
    while(palabra[i] != '\0') {
        if(isalpha(palabra[i])) {
            letras++;
        }
        if(palabra[i] == ' ') {
            printf("\n");
        }
        else {
            printf("%c", palabra[i]);
        }
        i++;
    }
    return letras;
}

int main()
{
    char palabra[50] = "Hola Mundo";
    int letras = contar_letras(palabra);
    printf("\nLa cantidad de letras es %d", letras);
    return 0;
}
