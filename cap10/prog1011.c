#include <stdio.h>
#include <stdlib.h> // Por causa da função exit

#define DATAFILE "data.dat"

int main(void)
{
  FILE *fp;
  int n;
  float v[10], value;

  // Ler os dados a partir do teclado
  for (int i=0; i<10; i++)
  {
    printf("Introduza o %dº nº real: ", i+1);
    scanf("%f", &v[i]);
  }

  // Abrir o ficheiro de dados
  if ((fp = fopen(DATAFILE, "w+b"))==NULL)
  {
    printf("Impossível Criar o ficheiro %s\n", DATAFILE);
    exit(1);
  }

  if (fwrite(v, sizeof(float), 10L, fp)!=10)
  {
    fprintf(stderr, "Não foram escritos todos os elementos!!!\n");
    exit(2);
  }

  printf("\nQual a posição que pretende ver 2..10: ");
  scanf("%d", &n);

  // Mostrar o n-ésimo valor
  fseek(fp, (n-1)*sizeof(float), SEEK_SET);  // a partir do início
  fread(&value, sizeof(float), 1L, fp);
  printf("\nO %dº valor introduzido foi %.2f\n", n, value);

  // Mostrar o (n-1)-ésimo valor
  fseek(fp, -2*sizeof(float), SEEK_CUR); // recuar 2 floats
  fread(&value, sizeof(float), 1L, fp);
  printf("O %dº valor introduzido foi %.2f\n", n-1, value);

  // Mostrar o primeiro valor
  rewind(fp);    // ou fseek(fp, 0L, SEEK_SET);
  fread(&value, sizeof(float), 1L, fp);
  printf("O 1º valor introduzido foi %.2f\n", value);

  // Mostrar o último valor
  fseek(fp, -sizeof(float), SEEK_END);
  fread(&value, sizeof(float), 1L, fp);
  printf("O último valor introduzido foi %.2f\n", value);

  fclose(fp);
  return 0;
}

