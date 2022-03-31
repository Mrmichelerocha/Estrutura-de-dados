/*Uma empresa contratou 15 funcionários temporários. De acordo com o valor das 
vendas mensais, os funcionários ganham pontos que determinarão seus salários ao 
final do mês. Faça um programa que:
–Cadastre os dados de cada funcionário;
–Calcule os pontos adquiridos e o salário total, considerando que cada R$100,00 
vendidos, o funcionário tem um ponto (cada ponto = R$1,00) ;
–Mostre o nome, salário, pontos, total de vendas e o salário final.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro {
  char nome[50];
  float salario;
  float totalvendas;
  float ponto;
  float salariofinal;

  float conta;

} cadastro;


int main() {
  int count, i, y, ponto;

  cadastro vendedor[2];


  count = 2;
  for (size_t i = 0; i < count; i++) {
    printf("Nome: \n" );
      fflush(stdin);
      gets(vendedor[i].nome);
      printf("Salario:  \n" );
        scanf("%f", &vendedor[i].salario );
          printf("qual seu total de vendas?\n" );
            scanf("%f", &vendedor[i].totalvendas );
    system("cls");
  }

  for (size_t i = 0; i < count; i++) {
    vendedor[i].conta =  vendedor[i].totalvendas;
      for (size_t ponto = 1; vendedor[i].conta >= 100; ponto++) {
        vendedor[i].conta = vendedor[i].conta - 100;
        vendedor[i].ponto = ponto;
      }
  }


  for (size_t i = 0; i < count; i++) {
    vendedor[i].salariofinal = vendedor[i].salario + vendedor[i].ponto;
  }



for (size_t i = 0; i < count; i++) {
  printf("\n nome: %s\n salario: %.2f\n total de vendas: %.2f\n pontos recebidos: %.0f \n salario final: %.2f ",vendedor[i].nome, vendedor[i].salario, vendedor[i].totalvendas, vendedor[i].ponto, vendedor[i].salariofinal   );
}
  return 0;
}
