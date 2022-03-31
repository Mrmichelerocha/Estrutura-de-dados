#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node
{
	int num;
	Node* prox;
};
typedef struct Node node;
 
// função para inserir um número (nó) na lista
void insereFim(node *LISTA, int numero)
{
	node *novo = (node *) malloc(sizeof(node));
	novo->num = numero;
	novo->prox = NULL;
	
	// inserção no fim da lista
	if(LISTA->prox == NULL)
		LISTA->prox = novo;
	else
	{
		node *aux = (node *) malloc(sizeof(node));
		aux = LISTA->prox;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}

void insereInicio(node *LISTA, int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	node *oldHead = LISTA->prox;
	novo->num = x;
	LISTA->prox = novo;
	novo->prox = oldHead;
}

void mostra(node *LISTA)
{
	if(!LISTA)
		printf("Lista não iniciada \n");	
		 
	if(LISTA->prox == NULL)
		printf("Lista Vazia \n");	
	else{
		node *aux;
		aux = LISTA->prox;
		while(aux != NULL)
		{
			printf("%i ",aux->num);
	    	aux = aux->prox;
		}
		printf("\n");
	}
}

void cria(node *LISTA)
{
	LISTA->prox = NULL;
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
  		return 1;
 	else
  		return 0;
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,	*atual;

		while(LISTA->prox != NULL){
			proxNode = LISTA->prox;
	   		free(LISTA);
	   		LISTA = proxNode;
	   		printf("valor removido \n");
	  	}
 	}
 	else
 		printf("Lista vazia already");
}

int busca(node *LISTA,int x)
{
	node *p;
	p = LISTA;
	
	while(p != NULL && p->num != x){
		p = p->prox;
	}

	if(p == NULL) {
        printf("Nao achou \n");
    }
	else{
        printf("Achou \n");
	}
}

void remove(node *LISTA, int v) {
	node *ant = NULL; /* ponteiro para elemento anterior */
	node *p = LISTA; /* ponteiro para percorrer a lista*/
	
	/* procura elemento na lista, guardando anterior */
	while (p!= NULL && p->num != v) {
		//printf("%i ",p->num);
		ant = p;
		p = p->prox;
	}
	
	if(p == NULL)
		printf("Valor nao encontrado \n");
	else
		/* retira elemento */
		if (ant == NULL) {
			/* retira elemento do inicio */
			LISTA = p->prox;
		}
		else {
			/* retira elemento do meio da lista */
			ant->prox = p->prox;
			free(p);
		}
}

int menu(){
	int opcao;
	printf("1 - Criar a lista\n");
	printf("2 - Inserir na lista\n");
	printf("3 - Remover da lista\n");
	printf("4 - Buscar valor\n");
	printf("5 - Remover a lista\n");
	printf("6 - Mostrar a lista\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main()
{
	int opcao, x;	
	node *LISTA = (node *) malloc(sizeof(node));
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: cria(LISTA);
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					insereInicio(LISTA, x);
					//insereFim(LISTA, x);
					break;
			case 3: printf("Elemento a ser removido: ");
					scanf("%d",&x);
					remove(LISTA, x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					busca(LISTA,x);
					break;
			case 5: libera(LISTA);
					break; 
			case 6: mostra(LISTA);
					break;
			} 
	}while(opcao !=0);
}


