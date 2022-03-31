#include <stdio.h>
#include <stdlib.h>

void intercalar (int v[],int aux[],int inicio, int meio,int fim){
 int au=0, i, meio2= meio-1, ini1=inicio;

 while(inicio <= meio2 && meio <= fim){
  if (v[inicio] < v[meio]){
   aux[au++] = v[inicio++];
  }
  else{
   aux[au++] = v[meio++];
  }
 }
 while(inicio<=meio2){
  aux[au++] = v[inicio++];
 }
 while(meio<=fim){
  aux[au++] = v[meio++];
 }

 for(i=0;i<au;i++){
  v[i+ini1]=aux[i];
 }
}

void mergeSort (int v[], int aux[], int inicio, int fim){
 int meio, i;

 if(inicio < fim){
  meio = (inicio + fim)/2;
  mergeSort(v,aux,inicio,meio);
  mergeSort(v,aux,meio+1,fim);
  intercalar(v,aux,inicio,meio+1,fim);
 }
}

int main(){
 int v[10],aux[10],i, num;

 printf("Digite a quantidade de numeros do vetor\n");
 scanf("%d", &num);

 printf("Digite um vetor com %d numeros\n", num);
 for (i = 0; i < num; i++) {
   scanf("%d", &v[i]);
 }

 mergeSort(v, aux, 0, 9);

 for(i = 0 ; i < num; i++){
  printf("%d ", v[i]);
 }

 return 0;
}
