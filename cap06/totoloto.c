#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS  49       // Total de Nºs do Jogo
#define NUM_LIN  7     // Nº de números apres. por linha no boletim
#define MIN_APOSTA  6  // Aposta Mínima - 6 Nºs

/* Declaração das Funções */
void inic_random();
void inic_array(int v[NUMS]);
int ler_nums_apostar();
void gerar_aposta(int *v, int n);
void apresentar_aposta(int res[]);

/*
 * Inicializa o gerador de números aleatórios com um número que depende
 * da hora a que se executa a função
 */
void inic_random()
{
  long ultime;
  time(&ultime);
  srand((unsigned) ultime);
}

/*
 * Inicializa a ZERO os elementos do array de controlo
 * dos números selecionados 
 */
void inic_array(int v[])
{
  for(int i=0; i<NUMS; i++)
     v[i]=0;
}

/*
 * Lê o número de Números a apostar. Aceita valores entre MIN_APOSTA e NUMS.
 * Aceita o valor ZERO para indicar que se quer terminar o Prog.
 */
int ler_nums_apostar()
{
  int n;
  do
   {
     printf("Quantos nºs quer apostar ( 0 - Terminar): ");
     scanf("%d", &n);
   }
  while ((n<MIN_APOSTA || n >NUMS) && n!=0);

  return n;
}

/*
 * Gera n NÃºmeros aleatÃ³rios e coloca a respetiva posição do array
 * com o valor 1, indicando que esse número foi selecionado.
 */
void gerar_aposta(int v[], int n)
{
  int indice;
  for (int i=1; i<=n; i++)
   { 
     indice = rand()%NUMS; // Devolve um número aleatório entre 0 e NUMS-1
     if (v[indice]==0)     // Valor ainda não foi selecionado 
       v[indice] = 1;
     else     // Este número já tinha sido selecionado,
       i--;   // logo decrementa-se o contador para voltar a
   }          // calcular mais uma vez o i-ésimo número aleatório
}

/*
 * Apresenta o formato do boletim colocando XX nos números
 * selecionados na aposta.
 */
void apresentar_aposta(int res[])
{
  for (int i=0; i<NUMS; i++)
    {
      if (res[i]==0)
        printf(" %2d", i+1);
      else
        printf(" XX");
      if ((i+1)%NUM_LIN==0) 
        putchar('\n');
    }
  putchar('\n');
}

int main(void)
{
  int arr[NUMS];
  int n_nums; /* Nº de Números a Jogar no jogo 6..49 */

  inic_random();
  while(1)
  {
    inic_array(arr);
    if ((n_nums = ler_nums_apostar())==0)
      break;
    gerar_aposta(arr, n_nums);  /* Gerar os Nºs a Apostar */
    apresentar_aposta(arr);
  }

  return 0;
}
