#include <stdio.h>
#include <string.h>
#include <stdlib.h>  /* Função exit    */
#include <ctype.h>   /* Função toupper */

#define FICH "dados.dat"  /* Ficheiro  com os Dados */

#define OP_INSERIR   '1'
#define OP_ALTERAR   '2'
#define OP_APAGAR    '3'
#define OP_LISTAR    '4'
#define OP_PESQUISAR '5'

#define OP_SAIR      '0'

#define OP_PESQ_IDADE '1'
#define OP_PESQ_NOME  '2'

char *mainMenu[]={
   "1. Inserir Registo",
   "2. Alterar Registo",
   "3. Apagar Registo",
   "4. Listar Registos",
   "5. Pesquisas",
   "0. Sair",
   NULL   /* Acabaram as Opções */
  };

char *searchMenu[]={
   "1. Pesquisar por Intervalo de Idades",
   "2. Pesquisar por Nome",
   "0. Voltar",
   NULL   /* Acabaram as Opções */
  };

typedef struct
{
  char  nome[30+1];
  int   idade;
  float salario;
  char  status; /* '*' Indica que o registo esta apagado */
} PESSOA;


 
void mensagem(char *msg);


/* Lê os dados de um registo introduzidos pelo utilizador */
void ler_pessoa(PESSOA *p)
{
  printf("Nome    : "); gets(p->nome);
  printf("Idade   : "); scanf("%d", &p->idade);
  printf("Salario : "); scanf("%f", &p->salario);
  p->status=' ';
}

/* Mostra no ecrã, os dados existente no registo */

void mostrar_pessoa(PESSOA p)
{
  printf("%-30s  %3d  %10.2f\n", p.nome, p.idade, p.salario);
}

/* Limpar o buffer do teclado */
void limpar_buffer()
{
  while (scanf("%*c")==1)
       ;
}

/* Grava os dados de uma pessoa no Ficheiro */
void gravar_pessoa(FILE*fp, PESSOA p)
{
  fseek(fp, 0L, SEEK_END);
  if (fwrite(&p, sizeof(p), 1L, fp)!=1)
    mensagem("Adicionar Pessoa: Falhou a escrita do Registo");
  else
    mensagem("Registo gravado com sucesso.");
}

/* Coloca um mensagem no ecrã */
void mensagem(char *msg)
{
  printf("%s", msg);
  printf("Prima <ENTER> para continuar");
  limpar_buffer();
  getchar();
}

/* Devolve a referência para o ficheiro de dados */
FILE * obter_ficheiro()
{
  FILE *fp=fopen(FICH, "r+b"); /* Tentar Abrir */

  if (fp==NULL)               /* Ficheiro não existe */
    fp=fopen(FICH, "w+b");     /* Tentar Criar */

  if (fp==NULL)
  {
    fprintf(stderr, "ERRO FATAL: Ficheiro de Dados\n");
    exit(1);
  }
  return fp;
}

/*
 * Faz um Menu Simples com as opções do array de Strings.
 * Selecciona a Opção, usando o 1º caráter de cada string.
 * Devolve o primeiro caráter da opção
 */
char menu(char *opcoes[])
{
  char op;

  while (1)
  {

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for(int i=0; opcoes[i]!=NULL; i++)
      printf("\t\t%s\n", opcoes[i]);

    printf("\n\n\t\tOpção: ");
    scanf(" %c", &op);
    limpar_buffer();

    for (int i=0; opcoes[i]!=NULL; i++)
      if (opcoes[i][0]==op)
        return op;
  }

}

void inserir_pessoa(FILE *fp)
{ PESSOA x;
  ler_pessoa(&x);
  gravar_pessoa(fp, x);
}

void alterar_pessoa(FILE*fp)
{ PESSOA x;
  long int n_reg;

  printf("Qual o nº do registo: ");
  scanf("%ld", &n_reg);
  if (fseek(fp, (n_reg-1)*sizeof(PESSOA), SEEK_SET)!=0)
  {
    mensagem("Registo inexistente ou problemas no posicionamento!!!");
    return;
  }

  if (fread(&x, sizeof(PESSOA), 1L, fp)!=1)
  {
    mensagem("Problemas na leitura do registo!!!");
    return;
  }

  if (x.status=='*')
  {
    mensagem("Um registo apagado não pode ser alterado!!!\n\n");
    return;
  }

  printf("\n\nDados Actuais\n\n");
  mostrar_pessoa(x);
  printf("\n\nNovos Dados\n\n");
  ler_pessoa(&x);

  // Recuar um Registo no Ficheiro
  fseek(fp, -(long) sizeof(PESSOA), SEEK_CUR);
  // Reescrever o Registo;
  fwrite(&x, sizeof(PESSOA), 1L, fp);
  fflush(fp); 
}

void apagar_pessoa(FILE*fp)
{ PESSOA x;
  long int n_reg;
  char resp;

  printf("Qual o Nº do Registo: ");
  scanf("%ld", & n_reg);fflush(stdin);

  if (fseek(fp, (n_reg-1)*sizeof(PESSOA), SEEK_SET)!=0)
  {
    mensagem("Registo inexistente ou problemas no posicionamento!!!");
    return;
  }

  if (fread(&x, sizeof(PESSOA), 1L, fp)!=1)
  {
    mensagem("Problemas na leitura do registo!!!");
    return ;
  }

  if (x.status=='*')
  {
    mensagem("Registo já está apagado!!!\n\n");
    return;
  }

  printf("\n\nDados Actuais\n\n");
  mostrar_pessoa(x);

  printf("\n\nApagar o registo (s/n)???: "); scanf(" %c", &resp);
  if (toupper(resp)!='S') return;

  x.status='*';

  // Recuar um registo no ficheiro
  fseek(fp, -(long) sizeof(PESSOA), SEEK_CUR);

  // Reescrever o fegisto;
  fwrite(&x, sizeof(PESSOA), 1L, fp);
  fflush(fp); 
}

void listar(FILE*fp)
{ long int n_linhas =0;
  PESSOA reg;

  rewind(fp);
  while(1)
  {
    if (fread(&reg, sizeof(reg), 1L, fp)!=1)
      break;/* Sair do Ciclo */

    if (reg.status=='*')
      continue ;  /* Passa ao próximo */
    mostrar_pessoa(reg);
    n_linhas++;
    if (n_linhas%20==0)
      mensagem("");
  }
  mensagem("\n\nFim da listagem "); /* No fim da Listagem */
}

void pesquisar_idades(FILE*fp, int ini, int fim)
{ PESSOA reg;
  rewind(fp);

  while (fread(&reg, sizeof(PESSOA), 1L, fp))
    if (reg.status!='*' && reg.idade>=ini && reg.idade<=fim)
      mostrar_pessoa(reg);

  mensagem("\n\nFim da listagem "); /* No fim da Listagem */
}

void pesquisar_nome(FILE*fp, char *s)
{ PESSOA reg;
  rewind(fp);

  while (fread(&reg, sizeof(PESSOA), 1L, fp))
    if (reg.status!='*' && strstr(reg.nome,s))
     mostrar_pessoa(reg);
  mensagem("\n\nFim da listagem "); /* No fim da Listagem */
}

int main(void)
{
  char opcao;
  FILE *fp = obter_ficheiro();

  while ((opcao=menu(mainMenu))!=OP_SAIR)
    switch(opcao)
    {
      case OP_INSERIR: inserir_pessoa(fp); break;
      case OP_ALTERAR: alterar_pessoa(fp); break;
      case OP_APAGAR:  apagar_pessoa(fp); break;
      case OP_LISTAR:  listar(fp); break;

      case OP_PESQUISAR:
        while((opcao=menu(searchMenu))!=OP_SAIR)
          switch (opcao)
           {
            case OP_PESQ_IDADE:
              { int n1, n2;
               printf("Qual o intervalo de Idades: ");
               scanf("%d%d", &n1, &n2);
               pesquisar_idades(fp, n1, n2);
                      break;
              }
            case OP_PESQ_NOME:
              { char string[BUFSIZ+1];
               printf("Qual o nome a procurar: ");
               gets(string);
               pesquisar_nome(fp, string);
              }
           }
    }
  return 0;
}

