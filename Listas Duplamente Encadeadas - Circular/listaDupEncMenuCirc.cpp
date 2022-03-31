#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node
{
	int num;
	Node* prox;
	Node* ant;
};
typedef struct Node node;

struct LDEC
{
    Node *cabeca;
    Node *cauda;
    int tamanho;
};
typedef struct LDEC ldec;

void inserirInicio(ldec *l,int valor) //Insere um n� no come�o da lista l
{
    if (l != NULL)
    {
        Node *no = (Node*) malloc (sizeof(Node));
        no->num = valor;
        if (l->tamanho == 0)
        {
            l->cabeca = no;
            l->cauda = no;
            no->ant = no;
            no->prox = no;
            l->tamanho++;
            return;
        }
        if (l->tamanho == 1)
        {
            l->cabeca->ant = no;
            l->cabeca->prox = no;
            no->prox = l->cabeca;
            no->ant = l->cauda;
            l->cabeca = no;
            l->tamanho++;
            return;
        }
        l->cabeca->ant = no;
        l->cauda->prox = no;
        no->ant = l->cauda;
        no->prox = l->cabeca;
        l->cabeca = no;
        l->tamanho++;
    }
}

void imprimirLista(ldec *l) //Imprime todos os valores dos n�s da lista
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
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

ldec *criarLdec() //Cria uma nova lista encadeada;
{
	ldec *l = (ldec*) malloc (sizeof(ldec));
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
    return l;
}

void buscarValor(ldec *l,int valor) //Mostra o n� que cont�m determinado valor da lista l
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    Node *no = l->cabeca;

    if(valor == no->num){ //imprime se primeiro
		printf("Achou %d \n", no->num);
		return;
	}
	no = no->prox;
    while (no != l->cabeca)
    {
        if(valor == no->num){
        	printf("Achou %d \n", no->num);
        	return;
		}
		no = no->prox;
    }
	if(no == l->cabeca)
		printf("Nao Achou \n ");
}

void removerValor(ldec *l,int valor) //Remove os n�s que cont�m determinado valor da lista l
{
	//printf("cabeca %d \n", l->cabeca->num);
	//printf("cauda %d \n", l->cauda->num);
   if ((l->tamanho == 0) || (l == NULL))
        return;
    Node *no = l->cabeca, *aux;
    while (no->prox != l->cabeca)
    {
        if (no == l->cabeca)
        {
            if (no->num == valor)
            {
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
                no->ant->prox = no->prox;
                no->prox->ant = no->ant;
                aux = no;
                no = no->ant;
                free(aux);
                l->tamanho--;
            }
        }
        no = no->prox;
    }

    if (no->num == valor) //condicao para o ultimo
    {
        l->cauda = no->ant;
        l->cauda->prox = l->cabeca;
        l->cabeca->ant = l->cauda;
        free(no);
        l->tamanho--;
    }
}


void removerPrimeiro(ldec *l) //Remove o primeiro n� da lista
{
   if ((l->tamanho == 0) || (l == NULL))
        return;
    if (l->tamanho == 1)
    {
        free (l->cabeca);
        l->cabeca = NULL;
        l->cauda = NULL;
        l->tamanho = 0;
        return;
    }
    Node *no = l->cabeca->prox;
    no->ant = l->cauda;
    l->cauda->prox = no;
    free(l->cabeca);
    l->cabeca = no;
    l->tamanho--;
}


void deletarLista(ldec *l) //Remove todos os n�s da lista e depois a deleta;
{
    if (((l)->tamanho == 0) || (l) == NULL)
        return;
    if ((l)->tamanho == 1)
    {
        Node *no = (l)->cabeca;
        free (no);
        free ((l));
        (l) = NULL;
        return;
    }
    while ((l)->tamanho > 0)
        removerPrimeiro((l));
    free ((l));
    (l) = NULL;
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
	ldec *LISTA = (ldec *) malloc(sizeof(ldec));
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
