#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam;


void inicia(node *PILHA){
 PILHA->prox = NULL;
 tam=0;
 printf("iniciou a lista\n");
}
int vazia(node *PILHA){
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}
node *aloca(){
 node *novo=(node *) malloc(sizeof(node));
 if(novo == NULL){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: ");
	scanf("%d", &novo->num);
  return novo;
 }
}
void push(node *PILHA){
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  node *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}
node *pop(node *PILHA){
 if(PILHA->prox == NULL){
  printf("PILHA ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = PILHA->prox,
    *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}
void imprime(node *PILHA){
 if(vazia(PILHA)){
   printf("PILHA vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = PILHA->prox;
 printf("PILHA:");
 while( tmp != NULL){
	  printf("%5d", tmp->num);
	  tmp = tmp->prox;
 }
 printf("\n");
 int count;
 for(count=0 ; count < tam ; count++)
	  printf("  ^  ");
	 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  	printf("%5d", count+1);


 printf("\n\n");
}
void libera(node *PILHA){
 if(!vazia(PILHA)){
  node *proxNode,
     *atual;

  atual = PILHA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}
void exclui(node *FILA) {
  node* q = FILA;
  while (q!=NULL) {
  node* t = q->prox;
  free(q);
  q = t;
  }
  free(FILA);
}

int menu(void){

 int opcao;
	printf("1 - Criar a pilha\n");
	printf("2 - Inserir na pilha PUSH\n");
	printf("4 - Remover da pilha POP\n");
	printf("6 - Remover a pilha\n");
	printf("7 - Mostrar a pilha\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}
void opcao(node *PILHA, int op){
 node *tmp;
 int opcao;
    switch(opcao){
      case 1:
			system("cls");
        libera(PILHA);
      break;
      case 2:
				system("cls");
          push(PILHA);
      break;
      case 4:
				system("cls");
        tmp= pop(PILHA);
        if(tmp != NULL)
        printf("Retirado: %3d\n\n", tmp->num);
      break;
      case 6:
				system("cls");
       exclui(PILHA);
      break;
      case 7:
				system("cls");
        imprime(PILHA);
      break;
		  default:
		   printf("Comando invalido\n\n");
 }
}

int main(void)
{
 node *PILHA = (node *) malloc(sizeof(node));
 if(!PILHA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(PILHA);
 int opt;

 do{
  opt=menu();
  opcao(PILHA,opt);
 }while(opt);

 free(PILHA);
 return 0;
 }

}
