#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char* strdup(const char*);

typedef struct
{
  char *city;
  int day;
  char month[20];
  int year;
} LOCAL_AND_DATA;

// Divide a string em tokens e carrega a estrutura apontada por d
void split_data(char *orig, LOCAL_AND_DATA *d)
{
  char *str = strdup(orig); // Criar uma cópia da string original
  if (str==NULL) return ;

  char *token = strtok(str, ",");  // Delimitador  ","

  if (token==NULL) {free(str); return;}

  d->city = strdup(token); // String alocada dinamicamente

  char delim[] = " /-"; // Delimitadores a considerar: Espaço, slash e hífen

  // Obter o valor do dia
  token = strtok(NULL, delim);
  if (token==NULL) {free(str); return;}
  d->day = atoi(token);

  // Obter o valor do mes
  token = strtok(NULL, delim);
  if (token==NULL) {free(str); return;}
  strcpy(d->month, token);

  // Obter o valor do ano
  token = strtok(NULL, delim);
  if (token==NULL) {free(str); return;}
  d->year = atoi(token);

  free(str);  // Libertar a memória temporária
}

int main(void)
{
  char str[][100] = {"Lisboa, 23 agosto 1999", 
                     "Vila Nova de Gaia, 18/Outubro/2001",
                     "Vila Pouca de Aguiar, 25-Dez-2002"
                    };

  LOCAL_AND_DATA data;
  for (int i=0; i<3; i++)
  {
    split_data(str[i], &data);
    printf("Data: %d/%s/%d \t\tLocal: %s\n", data.day, data.month, data.year, data.city);
    free(data.city);
  }

  return 0;
}
