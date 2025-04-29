#include <stdio.h>

typedef struct
{
  char Nome[40];
  int Idade;
} PESSOA1;

typedef struct
{
  char Nome[40];
  int Idade;
  char Sexo : 1;         /* 1 bit  */
  char Est_Civil : 2;    /* 2 bits */
} PESSOA2;

typedef struct
{
  char Nome[40];
  int Idade;
  int Sexo : 1;        /* 1 bit  */
  int Est_Civil : 2;   /* 2 bits */
} PESSOA3;

typedef struct
{
  char Nome[40];
  int Idade;
  int Sexo;
  int Est_Civil;
} PESSOA4;

int main()
{
  printf("sizeof(char) --> %lu  sizeof(int) --> %lu\n\n",
         sizeof(char), sizeof(int));
  printf("sizeof(PESSOA1) --> %lu\n", sizeof(PESSOA1));
  printf("sizeof(PESSOA2) --> %lu\n", sizeof(PESSOA2));
  printf("sizeof(PESSOA3) --> %lu\n", sizeof(PESSOA3));
  printf("sizeof(PESSOA4) --> %lu\n", sizeof(PESSOA4));

  return 0;
}
