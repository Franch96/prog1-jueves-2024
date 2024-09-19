// Escribir un algoritmo que permita procesar 2 arreglos ordenados   de n elementos.   
// Legajos(n) y Notas (n * 3) ya que por cada legajo hay 3 notas consecutivas .
//   Se desea obtener un listado con el promedio de cada alumno.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void promedio(int legajos[], int notas[],int n){
  for (int i =0;i<n;i++){
    // promedio legajo 0 = nota[0*3 +0] + nota[0*3 +1] + nota[0*3+2] / 3
    float promedio = (notas[i*3] + notas[(i*3)+1] + notas[(i*3)+2])/3 ;
    printf("el promedio del legajo %i es :%.2f\n", i , promedio);
  }
}
void promedio_v2(int legajos[], int notas[],int n){
  for (int i =0;i<n;i++){
    int acumulador = 0;
    // promedio legajo 0 = nota[0*3 +0] + nota[0*3 +1] + nota[0*3+2] / 3
    for (int j=i*3;j<=(i*3)+2;j++){
      acumulador+= notas[j];
    }
    float promedio = acumulador/3;
    printf("el promedio V2 del legajo %i es :%.2f\n", i , promedio);
  }
}


int main(){
  int n =3;
  int legajos[] = {4,5,10};
  int notas[] = {2,2,2,4,8,6,10,10,7};
  promedio(legajos,notas,n);
  promedio_v2(legajos,notas,n);

  return 0;
}
// 1*3
// 0*3 +1 
// 0*3 +2
// {4,5,10}
// 0, 1 ,2 
//  {2,2,2,4,8,5,10,10,9}
//  0,1,2-3,4,5-6,7,8