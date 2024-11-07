// En un archivo secuencial (por ejemplo “lluvias.txt”) se almacenan datos sobre la lluvia caída en un cierto período. 
// Cada línea corresponde a un día y contiene los siguientes datos: 
// Día-Mes-Anio-Precipitaciones (0 si no llovió)  
// Preparar un algoritmo con los procedimientos necesarios para: 
// Cargar los datos correspondientes a los 30 días del mes de septiembre del corriente año. / 
// Leer el archivo e informar por pantalla:cuántos días hubo sin lluvias, cuántos días
//  llovió  menos de 50 mm y cuántos llovió 50 mm ó más.  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIAS 5
struct precipitaciones {
    int dia;
    int mes;
    int anio;
    int ml;
};

void cargar_datos(){
    //  Cargar los datos correspondientes a los 10 días del mes de septiembre del corriente año. 
    FILE *file = fopen("lluvias.txt","w");

    struct precipitaciones lluvias[MAX_DIAS] = {
        {1,9,2024,10},
        {2,9,2024,50},
        {5,9,2024,0},
        {6,9,2024,0},
        {10,9,2024,11}
    };

    if(file==NULL){
        printf("el archivo no existe");
    }else{

        for (int i = 0; i< MAX_DIAS; i++){
            fprintf(file,"%d %d %d %d\n", lluvias[i].dia,lluvias[i].mes,lluvias[i].anio,lluvias[i].ml);
        }

    }
    fclose(file);

}

void leer_precipitaciones(){

    FILE *file = fopen("lluvias.txt","r");

    if(file==NULL){
        printf("el archivo no existe");
    }else{
        int contador_sin_lluvia,contador_lluvia_menor_50,contador_lluvia_mayor_50,dia,mes,anio,ml;
        contador_sin_lluvia =0;
        contador_lluvia_mayor_50 =0;
        contador_lluvia_menor_50 = 0;
        while(fscanf(file,"%d %d %d %d" ,&dia,&mes,&anio,&ml) == 4) {
            if (ml == 0){
                contador_sin_lluvia++;
            }else if (ml>=50)
            {
                contador_lluvia_mayor_50++;
            }else{
                contador_lluvia_menor_50++;
            }
            
        }
        fclose(file);

        printf("sin lluvia %d\n",contador_sin_lluvia);
        printf("lluvia mayor igual a 50 %d\n",contador_lluvia_mayor_50);
        printf("lluvia menor a 50 %d\n",contador_lluvia_menor_50);
    }

}


int main(){

    cargar_datos();
    leer_precipitaciones();

}

