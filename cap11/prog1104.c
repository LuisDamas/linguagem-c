#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_NOME 40

typedef struct
{
  unsigned n;
  char nome[MAX_NOME+1];
} REGISTO;

typedef struct
{
  REGISTO arr[MAX];
  int conta;
} LISTA;

void inic(LISTA * ptr)
{
  ptr->conta=0;
}

int lista_cheia(LISTA lst)
{
  return lst.conta>=MAX;
}

int inserir(LISTA *ptr, REGISTO reg)
{
  if (lista_cheia(*ptr))
	 return -1;
  ptr->arr[ptr->conta] = reg;
  return ptr->conta++;
}

int gravar(LISTA lst, char *filename)  /* Versão 1 */
{ 
  FILE *fp=fopen(filename, "wb");
  if (fp==NULL) return 0;

  for (int i=0 ; i<lst.conta; i++)
    if (fwrite(&lst.arr[i], sizeof(REGISTO), 1L,fp)!=1) 
     return 0;
  fclose(fp);
  return 1;
}

int gravar_v2(LISTA lst, char *filename)  /* Versão 2 */
{
  FILE *fp=fopen(filename, "wb");
  if (fp==NULL) return 0;

  if (fwrite(lst.arr, sizeof(REGISTO), (long) lst.conta, fp)!= lst.conta)
     return 0;
  fclose(fp);
  return 1;
}

int carregar_lista(LISTA *ptr, FILE *fp)
{ REGISTO reg;
  rewind(fp);  /* Ir para o principio do ficheiro */
  while (fread(&reg, sizeof(reg), 1L,fp)==1)
    if (inserir(ptr, reg)==-1) 
      return 0;
  return 1;
}

void listar(LISTA lst)
{
  puts("---- LISTA (inicio) ----");
  for (int i=0; i<lst.conta; i++)
    printf("%2d: %d %s\n",i+1, lst.arr[i].n , lst.arr[i].nome);
  puts("---- LISTA (fim) -------\n");
}


int main(void)
{
  REGISTO regs[] = {{50, "Rui"},{22, "Ana"},
                   {77, "Isabel"}, {99, "Carlos"}
                  };
  LISTA lista;
  
  inic(&lista);
  listar(lista);

  // Adicionar os registos à lista
  for (int i=0; i<sizeof(regs)/sizeof(regs[0]); i++)
    inserir(&lista, regs[i]);
  listar(lista);

  if (gravar(lista, "lista.dat"))
    puts("Registos gravados com sucesso.");
  else
    puts("Problemas na gravação dos registos.");

  // Carregar os registos existentes em ficheiro
  // ja lista já existente, adicionando-os ao fim
  
  FILE *fp = fopen("lista.dat", "rb");
  if (fp==NULL)
  {
    printf("Não foi possível abrir o ficheiro de dados");
    return 1;
  } 

  carregar_lista(&lista, fp);
  puts("Depois de adicionados os registos à lista 1x");
  listar(lista);

  // Voltar a carregar os registos para ver se os limites
  // não são violados

  carregar_lista(&lista, fp);
  fclose(fp);
  puts("Depois de adicionados os registos à lista 2x");
  listar(lista);

 return 0;
}

