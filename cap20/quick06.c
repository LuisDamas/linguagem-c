#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR 50

char **criar_array_nomes(int n_strings)
{
  char ** arr = (char**) malloc(sizeof(char*) * n_strings);
  if (arr==NULL) return NULL;

  for (int i=0; i<n_strings; i++)
  {
    arr[i] = (char*) malloc(MAX_STR);
    if (arr[i]==NULL) return NULL;
  }

  return arr;
}

int compare_strings(const void * s1, const void * s2)
{
  return strcmp(*((char**) s1), *((char**) s2));
}

int main(int argc, char*argv[])
{
  FILE *fp;

  clock_t ini, fim;
  char **nomes; // Futuro array de nomes

  if (argc!=3)
  {
    fprintf(stderr,"Sintaxe: %s ficheiro n-strings\n", argv[0]);
    return 1;
  }


  if ((fp = fopen(argv[1],"rt")) == NULL)
  {
    fprintf(stderr,"Impossível abrir o ficheiro: %s\n", argv[1]);
    return 2;
  }

  int n_nomes;
  char aux[MAX_STR];

  if ((n_nomes = atoi(fgets(aux, MAX_STR ,fp)))==0) 
  {
    fprintf(stderr,"A primeira linha do ficheiro não contém o número de linhas que o ficheiro contém.\n");
    return 3;
  }

  if (atoi(argv[2])!=0) 
    n_nomes = atoi(argv[2]);

  // Criar o array com referências para futuras strings
  if ((nomes = criar_array_nomes(n_nomes))==NULL)
  {
    fprintf(stderr,"Impossível criar a memória necessária.\n");
    return 4;
  }

  for (int i=0; i<n_nomes; i++)
    if (fgets(nomes[i], MAX_STR, fp)!=NULL)
      if (nomes[i][strlen(nomes[i])-1]<' ') 
        nomes[i][strlen(nomes[i])-1]='\0';


  ini = clock();
  puts("Sorting: start . . .");
  qsort(nomes, n_nomes, sizeof(char*), compare_strings);
  puts("Sorting: done!");
  fim = clock();

  printf("%d strings ordenadas em %.2lf segundos\n", n_nomes, ((double)fim-ini)/CLOCKS_PER_SEC);

  return 0;
}
