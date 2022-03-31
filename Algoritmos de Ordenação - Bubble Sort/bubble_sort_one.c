#include<stdio.h>
#include<stdlib.h>
void swap_troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int *v, int n){
    if (n < 1)return;

    for (int i=0; i<n; i++)
        if (v[i] > v[i+1])
            swap_troca(&v[i], &v[i+1]);
    bubble_sort(v, n-1);
}
void print_imprime(int *v, int tam) {
  int i;
  printf("\n\n");
  for(i=0;i<tam;i++){
    printf("%d ",v[i]);
  }
}
int main(){
  int tam,i,*v;

  printf("Digite quantos numeros tera o vetor\n");
  scanf("%d", &tam);
  v=(int*)malloc(tam*sizeof(int));


  printf("Digite %d numeros\n", tam);
  for (i = 0; i < tam; i++) {
    scanf("%d", &v[i]);
  }

  bubble_sort(v,tam-1);
  print_imprime(v,tam);

  return 0;
}
