#include <stdio.h>

#define DIM 3
#define BRANCO ' '

// Declaração das funções
void inic(char tab[ ][DIM]);
void mostrar(char tab[DIM][DIM]);

/* Inicializa o tabuleiro */
void inic(char tab[ ][DIM])    // Omitir uma dimensão
{
  for(int i=0; i<DIM; i++)
    for(int j=0; j<DIM; j++)
      tab[i][j]=BRANCO;
}

/* Mostra o tabuleiro */
void mostrar(char tab[DIM][DIM])   // Ambas as Dimensões
{
  for (int i=0; i<DIM; i++)
  {
    for (int j=0; j<DIM; j++)
      printf(" %c %c", tab[i][j], j==DIM-1? ' ' : '|');

    if (i!=DIM-1) 
      printf("\n-----------");
    putchar('\n');
  }
}

int main(void)
{
  char tabuleiro[DIM][DIM];
  int pos_x, pos_y;
  char ch = 'X';       // Símbolo a usar na primeira jogada 
  int n_jogadas = 0;

  inic(tabuleiro);
  while (1)            // Ciclo Infinito 
  {
    mostrar(tabuleiro);

    printf("\nIntroduza a posição de jogo (Linha Coluna): ");
    scanf("%d %d", &pos_x, &pos_y);
    pos_x--; pos_y--;  // Pois os índices do tab começam em 0 

    if (tabuleiro[pos_x][pos_y]==BRANCO)   // Posição livre no tabuleiro
    {
      tabuleiro[pos_x][pos_y] = ch = ((ch == '0') ? 'X' : '0');
      n_jogadas++;
    }
    else
      printf("Posição já ocupada\nJogue Novamente!!!\n");

    if (n_jogadas==DIM*DIM)
      break;
  }

  mostrar(tabuleiro);
  return 0;
}

