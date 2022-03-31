#include <stdio.h>
void Quick(int vetor[10], int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);

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

  Quick(array,0,4);
  printf("\nArray em ordem crescente: ");
  printArray(array,tamanho);

 return 0;
}
