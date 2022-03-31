#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Arvore;

/* Fun��o que cria uma �rvore */
Arvore* createArvore()
{
  return NULL;
}

/* Fun��o que verifica se uma �rvore � vazia */
int ArvoreIsEmpty(Arvore* t)
{
  return t == NULL;

}

/* Fun��o que mostra a informa��o da �rvore */
void mostraArvore(Arvore* t)
{
  /* Essa fun��o imprime os elementos de forma recursiva */

  printf("<"); /* nota��o para organizar na hora de mostrar os elementos */
  if(!ArvoreIsEmpty(t))
  {
    /* Mostra os elementos em pr�-ordem */
    printf("%d ", t->num); /* mostra a raiz */
    mostraArvore(t->sae); /* mostra a sae (sub�rvore � esquerda) */
    mostraArvore(t->sad); /* mostra a sad (sub�rvore � direita) */
  }
  printf(">"); /* nota��o para organizar na hora de mostrar os elementos */
}

/* Fun��o que insere um dado na �rvore */
void insertArvore(Arvore** t, int num)
{
  /* Essa fun��o insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (Arvore*)malloc(sizeof(Arvore)); /* Aloca mem�ria para a estrutura */
    (*t)->sae = NULL; /* Sub�rvore � esquerda � NULL */
    (*t)->sad = NULL; /* Sub�rvore � direita � NULL */
    (*t)->num = num; /* Armazena a informa��o */
  } else {
    if(num < (*t)->num) /* Se o n�mero for menor ent�o vai pra esquerda */
    {
      /* Percorre pela sub�rvore � esquerda */
      insertArvore(&(*t)->sae, num);
    }
    if(num > (*t)->num) /* Se o n�mero for maior ent�o vai pra direita */
    {
      /* Percorre pela sub�rvore � direita */
      insertArvore(&(*t)->sad, num);
    }
  }
}

/* Fun��o que verifica se um elemento pertence ou n�o � �rvore */
int isInArvore(Arvore* t, int num) {

  if(ArvoreIsEmpty(t)) {
    return 0;
  }

  return t->num==num || isInArvore(t->sae, num) || isInArvore(t->sad, num);
}

int main()
{
  Arvore* t = createArvore(); /* cria uma �rvore */

  insertArvore(&t, 14);
  insertArvore(&t, 15);
  insertArvore(&t, 4);
  insertArvore(&t, 9);
  insertArvore(&t, 7);
  insertArvore(&t, 18);
  insertArvore(&t, 3);
  insertArvore(&t, 5);
  insertArvore(&t, 16);
  insertArvore(&t, 4);
  insertArvore(&t, 20);
  insertArvore(&t, 17);
  insertArvore(&t, 9);
  insertArvore(&t, 14);
  insertArvore(&t, 5);

  mostraArvore(t); /* Mostra os elementos da �rvore em pr�-ordem */

  if(ArvoreIsEmpty(t)) /* Verifica se a �rvore est� vazia */
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }
  
  if(isInArvore(t, 15)) { /* Verifica se o n�mero 15 pertence a �rvore */
    printf("\nO numero 15 pertence a arvore!\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore!\n");
  }

  if(isInArvore(t, 22)) { /* Verifica se o n�mero 22 pertence a �rvore */
    printf("\nO numero 22 pertence a arvore!\n\n");
  } else {
     printf("\nO numero 22 NAO pertence a arvore!\n\n");
  }

  free(t); /* Libera a mem�ria alocada pela estrutura �rvore */

  return 0;
}
