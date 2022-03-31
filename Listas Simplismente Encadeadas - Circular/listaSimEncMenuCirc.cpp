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
 
struct LSEC
{
    Node *cabeca;
    Node *cauda;
    int tamanho;
};
typedef struct LSEC lsec;
 
void inserirInicio(lsec *l,int valor)//Insere um nó no começo da lista
{
    if (l != NULL)
    {
        Node *no = (Node*) malloc (sizeof(Node));
        no->num = valor;
        if (l->tamanho == 0)
        {
            l->cabeca = no;
            l->cauda = no;
            no->prox = no;
            l->tamanho++;
        }
        else{
		    if (l->tamanho == 1)
		    {
		        l->cabeca->prox = no;
				no->prox = l->cabeca;
		        l->cabeca = no;
		        l->tamanho++;
		    }
		    else {
		        l->cauda->prox = no;
		        no->prox = l->cabeca;
		        l->cabeca = no;
		        l->tamanho++;	
			}
		}
    }
    //printf("l cabeca %d \n", l->cabeca->num);	
    //printf("l cauda %d \n", l->cauda->num);	
}
 
void imprimirLista(lsec *l)//Imprime todos os valores dos nós da lista
{
    if ((l->tamanho == 0) || (l == NULL)){
    	printf("Lista vazia\n");
    	return;
	}
    Node *no = l->cabeca;

    printf("%d ", no->num); //imprime o primeiro
    no = no->prox;
    while (no != l->cabeca)
    {
        printf("%d ", no->num);
        no = no->prox;
    }
    printf(" \n");
}
 
lsec *criarLdec()//Cria uma nova lista encadeada;
{
	lsec *l = (lsec*) malloc (sizeof(lsec));
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
    return l;
}

void buscarValor(lsec *l,int valor) //Remove os nós que contém determinado valor da lista l
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    Node *no = l->cabeca;
    
    if(valor == no->num){ //imprime se primeiro
		printf("Achou %d \n", no->num);
		return;
	}
	no = no->prox;
    while (no != l->cabeca) //caminha na lista
    {
        if(valor == no->num){
        	printf("Achou %d \n", no->num);	// mostra se achou
        	return;
		}
		no = no->prox; //avanca
    }
	if(no == l->cabeca) //mostra msg se nao achou 
		printf("Nao Achou \n");
}

void removerPrimeiro(lsec *l) //Remove o primeiro nó da lista
{
	if ((l->tamanho == 0) || (l == NULL))
        return;
    if (l->tamanho == 1)
    {
        free (l->cabeca);
        l->cabeca = NULL;
        l->cauda = NULL;
        l->tamanho = 0;
    }
    else{
    	Node *no = l->cabeca->prox;
	    l->cauda->prox = no;
	    free(l->cabeca);
	    l->cabeca = no;
	    l->tamanho--;
	}
}

void removerValor(lsec *l,int valor) //Remove os nós que contém determinado valor da lista l
{
   if ((l->tamanho == 0) || (l == NULL))
        return;
    Node *no = l->cabeca, *ant = l->cabeca, *aux;

	while (no->prox != l->cabeca)
    {
        if (no == l->cabeca)
        {
            if (no->num == valor)
            {
    			//printf("cabeca \n");
                l->cabeca = no->prox;
                l->cauda->prox = l->cabeca;
                free (no);
                l->tamanho--;
                no = l->cabeca;
            }
        }
        else
        {
        	
            if (no->num == valor)
            {
            	//printf("meio \n");
                ant->prox = no->prox;
				aux = no;
                free(aux);
                l->tamanho--;
            }
        }
        ant = no;
		no = no->prox;
    }

    if (no->num == valor) //condicao para o ultimo
    {
    	//printf("cauda \n");
        l->cauda = ant;
        l->cauda->prox = l->cabeca;
        free(no);
        l->tamanho--;
    }	
}

void deletarLista(lsec *l) //Remove todos os nós da lista 
{
    if ((l->tamanho == 0) || (l) == NULL)
        return;
    if (l->tamanho == 1)
    {
        Node *no = (l)->cabeca;
        free (no);
        free (l);
        l = NULL;
        return;
    }
    while (l->tamanho > 0)
        removerPrimeiro(l);
    free (l);
    l = NULL;
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

int main() //funcao principal
{
	int opcao, x;	
	lsec *LISTA = (lsec *) malloc(sizeof(lsec));
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: LISTA = criarLdec();
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					//insereOrdenado(LISTA, x);
					//insereFim(LISTA, x);
					inserirInicio(LISTA, x);
					break;
			case 3: printf("Elemento a ser removido: ");
					scanf("%d",&x);
					removerValor(LISTA, x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					buscarValor(LISTA,x);
					break;
			case 5: deletarLista(LISTA);
					break; 
			case 6: imprimirLista(LISTA);
					break;
			} 
	}while(opcao !=0);
}


