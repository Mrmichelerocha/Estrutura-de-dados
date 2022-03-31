#include <stdio.h>

void selection_sort(int num[], int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void printArray(int array[], int tamanho){
  for(int i=0; i<tamanho; i++){
    printf("\n\t\t\t%d", array[i]);
  }
}

int main(int argc, char** argv){
 int array[100], tamanho = 5;

 printf("\n\t Entre com os elementos do array...:");
 for(int i = 0; i < tamanho;i++){
    printf("\nDigite o %d numero: ",i+1);
    scanf("%d",&array[i]);
 }

  selection_sort(array,tamanho);
  printf("\nArray em ordem crescente: ");
  printArray(array,tamanho);

 return 0;
}
