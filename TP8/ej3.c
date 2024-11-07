/*Dado un Archivo de acceso directo con la siguiente estructura de registro:
typedef struct rcliente {
int id_cli;                // Número de cliente (válido entre 1000 y 9000)
char ape[40];          // Apellido
char telef[40];         // Teléfono
float saldo;             // Saldo del cliente
int estado;              // Estado de cliente 0=Inactivo, 1=Activo
} rcliente;
Realizar una función que recibe el nombre del archivo binario (String), 
el número de cliente (Entero) y un entero indicando el Estado y 
modifique el valor del campo estado correspondiente a ese cliente retornando 0 (cero) si la operación fue exitosa y
 -1 (menos 1) si el número de cliente no corresponde a un cliente válido. El archivo se debe abrir y cerrar en la función.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE_ARCHIVO 10
#define CANTIDAD_CLIENTES 5


typedef struct rcliente {
    int id_cli;                // Número de cliente (válido entre 1000 y 9000)
    char ape[40];          // Apellido
    char telef[40];         // Teléfono
    float saldo;             // Saldo del cliente
    int estado;              // Estado de cliente 0=Inactivo, 1=Activo
} rcliente;

void cargar_archivo(char archivo_clientes[MAX_NOMBRE_ARCHIVO]){

    struct rcliente clientes[CANTIDAD_CLIENTES] = {
        {1000,"rodri","123456",100,1},
        {1001,"quiro","321654",10000,1},
        {1002,"Chappe","987456",50,0},
        {1003,"lalala","555 555",80,1},
        {1004,"casa","999887",0,0},
    };

    FILE *file = fopen(archivo_clientes , "wb");

    if (file == NULL){
        printf("No existe el archivo");
    }else{
        fwrite(clientes,sizeof(struct rcliente),CANTIDAD_CLIENTES,file);
        
        for (int i =0;i<CANTIDAD_CLIENTES;i++){
            fwrite(&clientes[i],sizeof(struct rcliente),1,file);
        }

    }
    fclose(file);
}

int editar_cliente(char nombre_archivo[MAX_NOMBRE_ARCHIVO],int id,int estado){

    FILE *file = fopen(nombre_archivo, "rb+");
    int no_encontrado =1;
    if (file == NULL){
        printf("ERROR");
    }else{
        struct rcliente cliente;
        while(fread(&cliente,sizeof(struct rcliente),1,file) == 1 && no_encontrado){
            if(cliente.id_cli == id){
                no_encontrado=0;
                cliente.estado = estado;
                fseek(file,-sizeof(struct rcliente),SEEK_CUR);
                fwrite(&cliente,sizeof(struct rcliente),1, file);
            }
        }
    }
    int res = -1;
    if (no_encontrado == 0){
        res = 0;
    }
    return res;
}

void mostrar(char nombre_archivo[MAX_NOMBRE_ARCHIVO]){
    FILE *file = fopen(nombre_archivo, "rb");
    if (file == NULL){
        printf("ERROR");
    }else{

        struct rcliente cliente;        
        while (fread(&cliente,sizeof(struct rcliente),1,file) == 1)
        {
            printf(" %d %s %s %f %d \n",cliente.id_cli,cliente.ape,cliente.telef,cliente.saldo,cliente.estado);
        }
        fclose(file);
    }
}


int main(){

    // cargar_archivo("cli");
    printf("------------------archivo cargado----------\n");
    mostrar("cli");
    int id_cliente = 1002;
    int estado = 0;
    int resultado_editar_cliente;
    resultado_editar_cliente = editar_cliente("cli",id_cliente,estado);
    printf("------------------archivo editado----------\n");
    printf("resultado editar : %d \n",resultado_editar_cliente);
    mostrar("cli");
    return 0;
}