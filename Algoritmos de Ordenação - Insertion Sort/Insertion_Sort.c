#include <stdio.h>

void insertionSortC(int array[], int tamanho) {
  int i, j, tmp;
  for (i = 1; i < tamanho; i++) {
    j = i;
    while (j > 0 && array[j - 1] > array[j]) {
      tmp = array[j];
      array[j] = array[j - 1];
      array[j - 1] = tmp;
      j--;
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

  insertionSortC(array,tamanho);
  printf("\nArray em ordem crescente: ");
  printArray(array,tamanho);

 return 0;
}
