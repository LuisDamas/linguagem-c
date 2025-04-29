#include <stdio.h>

int main(void)
{
  char opcao;
  do
  {
    printf("\tM E N U    P R I N C I P A L\n");
    printf("\n\t\tClientes");
    printf("\n\t\tFornecedores");
    printf("\n\t\tEncomendas");
    printf("\n\t\tSair");
    printf("\n\n\t\t\tOpçao: ");
    scanf(" %c", &opcao);

    switch (opcao)
    {
       case 'c':
       case 'C': puts("Opção CLIENTES"); break;
       case 'f':
       case 'F': puts("Opção FORNECEDORES"); break;
       case 'e':
       case 'E': puts("Opção ENCOMENDAS"); break;
       case 's':
       case 'S': break; // Não faz nada 
       default : puts("Opção INVALIDA!!!");
    }
    scanf("%*c"); // ignorar o <ENTER> que ficou no buffer
    puts("Prima <ENTER> para continuar . . .");
    getchar();
  }
  while (opcao!= 's' && opcao != 'S');

  return 0;
}

