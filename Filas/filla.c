#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam;


void cria(node *FILA){
 FILA->prox = NULL;
 tam=0;
}
int vazia(node *FILA){
 if(FILA->prox == NULL)
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
void insere(node *FILA){
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(FILA))
  FILA->prox=novo;
 else{
  node *tmp = FILA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}
node *retira(node *FILA){
 if(FILA->prox == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  node *tmp = FILA->prox;
  FILA->prox = tmp->prox;
  tmp->prox =NULL;
  free(tmp->prox);
  tam--;
  return tmp;
 }
}
void imprime(node *FILA){
 if(vazia(FILA)){
  printf("Fila vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = FILA->prox;
 printf("Fila :");
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
void libera(node *FILA){
 if(!vazia(FILA)){
  node *proxNode,
     *atual;

  atual = FILA->prox;
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
 printf("Escolha a opcao\n");
 printf("1 - Criar a pilha\n");
 printf("2 - Adicionar Elemento na Fila\n");
 printf("4 - Retirar Elemento da Fila\n");
 printf("6 - Remover a pilha\n");
 printf("7 - Mostrar a pilha\n");
 printf("0 - Sair\n");
 scanf("%i",&opcao);
 return(opcao);
}
void opcao(node *FILA, int op){
 node *tmp;
 switch(op){

  case 1:
    system("cls");
   libera(FILA);
   cria(FILA);
   break;

  case 2:
    system("cls");
   insere(FILA);
   break;

  case 4:
    system("cls");
   tmp= retira(FILA);
   if(tmp != NULL){
    printf("Retirado: %3d\n\n", tmp->num);
    libera(tmp);
   }
   break;
  case 6:
    system("cls");
    exclui(FILA);
  break;
  case 7:
    system("cls");
   imprime(FILA);
   break;
  default:
   printf("Comando invalido\n\n");
 }
}


int main(){
 node *FILA = (node *) malloc(sizeof(node));
 if(FILA == NULL){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 cria(FILA);
 int opt;

 do{
  opt=menu();
  opcao(FILA,opt);
 }while(opt);

 free(FILA);
 return 0;
 }
}
