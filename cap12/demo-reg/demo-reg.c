#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reg.h"

#define FILE_DATA "dados.dat"

REG arr[] = {{"Carlos",  1.85, 67},
             {"Beatriz", 1.62, 27},
             {"Sofia",   1.49, 50},
             {"Raquel",  1.72, 18}
            };
REG extra = {"Bigfoot", 2.35, 25};

FILE * inic()
{
  FILE *fp;
  if ((fp=fopen(FILE_DATA, "wb+"))==NULL)
  {
     fprintf(stderr, "Impossível criar o ficheiro %s\n", FILE_DATA);
     exit(1);
  }

  long n_regs = sizeof(arr)/sizeof(REG);
  if (fwrite(arr, sizeof(REG), n_regs, fp)!=n_regs)
  {
    fprintf(stderr, "Problemas na escrita dos registos\n");
    exit(2);
  };

  return fp;
}

void print_record(REG rec)
{
  printf("%-30s\t%.2fm\t%i anos\n", rec.nome, rec.altura, rec.idade);
}

void list_all(FILE *fp)
{
  REG reg;
  
  // Ir para o início do ficheiro
  rewind(fp); // fseek(fp, 0L, SEEK_CUR);
  puts("--- List All ---");
  while (fread(&reg, sizeof(reg), 1, fp)==1)
  {
    printf("%lu: ", ftell(fp)/sizeof(reg));
    print_record(reg);
  }
  puts("--- (end) ------\n");
}

void list_all_reverse(FILE *fp)
{
  REG reg;
  // Ir para o início do último registo
  if (fseek(fp, -sizeof(reg), SEEK_END)!=0)
    return; // problemas com o posicionamento
  
  puts("--- List All Reverse ---");
  do
  {
    if (fread(&reg, sizeof(reg), 1, fp)!=1)
      return; // não conseguiu ler
    printf("%lu: ", ftell(fp)/sizeof(reg));
    print_record(reg);
  }  // Andar 2 registos para trás
  while (fseek(fp, -2*sizeof(reg), SEEK_CUR)==0);
  puts("--- (end) ------\n");
}

unsigned long count_records(FILE* fp)
{
  // Posicionar no final do ficheiro
  fseek(fp, 0L, SEEK_END);
  return ftell(fp)/sizeof(REG);
}

void append_record(FILE* fp, REG reg) 
{
  fseek(fp, 0L, SEEK_END);
  fwrite(&reg, sizeof(reg), 1L, fp);
}

REG* read_record(FILE *fp, int pos)
{
  REG *ptr = malloc(sizeof(REG));
  if (ptr==NULL) 
  {
    fprintf(stderr, "Não há memória suficiente.");
    return NULL;
  }

  // Posicionar-se antes do registo índice=(pos-1)
  if (fseek(fp, (pos-1)*sizeof(REG), SEEK_SET)!=0)
  {
    fprintf(stderr, "Não existe um registo na posição %d\n", pos);
    free(ptr);
    return NULL;
  }

  // Ler o registo na posição onde estamos
  if (fread(ptr, sizeof(REG), 1L, fp)!=1)
  {
    fprintf(stderr, "Não foi possível ler o registo na posição %d\n", pos);
    free(ptr);
    return NULL;
  }

  return ptr;
}
void swap_records(FILE*fp, int pos1, int pos2) 
{
  REG *r1, *r2;
  
  if ((r1=read_record(fp, pos1))==NULL)
    return;
  if ((r2=read_record(fp, pos2))==NULL)
    return;

  // Escrever r2 em pos1
  fseek(fp, (pos1-1)*sizeof(REG), SEEK_SET);
  fwrite(r2, sizeof(*r2), 1L, fp);

 // Escrever r1 em pos2
  fseek(fp, (pos2-1)*sizeof(REG), SEEK_SET);
  fwrite(r1, sizeof(*r1), 1L, fp);

 // Libertar a memória
 free(r1); free(r2);
}

// Cria uma estrutura dinamicamente para
// conter todos os registos do ficheiro
REG* load_all(FILE*fp)
{
  long count = count_records(fp);
  REG *arr = malloc(count*sizeof(REG));

  if (arr==NULL)
    return NULL;

  fseek(fp, 0L, SEEK_SET);
  fread(arr,  sizeof(REG), count, fp);
  return arr;
}

int main(void)
{
  FILE *fp = inic();

  list_all(fp);
  list_all_reverse(fp);
  printf("Nº de registos: %lu\n\n", count_records(fp));
  
  append_record(fp, extra);
  list_all(fp);
  printf("Nº de registos: %lu\n\n", count_records(fp)); 

  swap_records(fp, 1, 5);
  list_all(fp);
  printf("Nº de registos: %lu\n\n", count_records(fp));

  REG *regs = load_all(fp);
  puts("--- Registos em memória ---");
  for (int i=0; i<count_records(fp); i++)
  {
    printf("regs[%d] : ", i);
    print_record(regs[i]);
  }
  puts("---------------------------");

  free(regs);
  fclose(fp);
  return 0;
}
