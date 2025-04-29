#include <stdio.h>

#define DIM 3
#define BRANCO ' '

// Declaração das funções
void inic(char tab[ ][DIM]);
void mostrar(char tab[DIM][DIM]);

int linha_vencedora(char linha[], char ch);
int coluna_vencedora(char mat[DIM][DIM], int n_col, char ch);
int diagonal_vencedora(char mat[DIM][DIM], char ch);

int ganhou(char tab[DIM][DIM], char ch);

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

/* Verifica se a linha está preenchida com o char ch) */
/* Devolve um valor lógico */
int linha_vencedora(char linha[], char ch) 
{
  return linha[0]==linha[1] && 
         linha[1]==linha[2] &&
         linha[0]==ch;
}

/* Verifica se a coluna n_col está totalmente preenchida */
/* com o char ch */
int coluna_vencedora(char mat[DIM][DIM], int n_col, char ch)
{
  return mat[0][n_col]==mat[1][n_col] &&
         mat[1][n_col]==mat[2][n_col] &&
         mat[0][n_col]==ch;
}

/* Verifica se alguma das diagonais está totalmente */
/* preenchida com o char ch */
int diagonal_vencedora(char mat[DIM][DIM], char ch)
{
  return (mat[0][0]==mat[1][1] &&
          mat[1][1]==mat[2][2] &&
          mat[0][0]==ch)
         ||
         (mat[0][2]==mat[1][1] &&
          mat[1][1]==mat[2][0] &&
          mat[0][2]==ch);
}

/* Verifica se o jogagor associado ao char ch */
/* ganhou o jogo */
int ganhou(char tab[DIM][DIM], char ch)
{
  if (linha_vencedora(tab[0], ch) || linha_vencedora(tab[1], ch) || linha_vencedora(tab[2], ch))
    return 1;
  if (coluna_vencedora(tab, 0, ch) || coluna_vencedora(tab, 0, ch) || coluna_vencedora(tab, 0, ch))
    return 1;
  if (diagonal_vencedora(tab, ch))
    return 1;
  return 0;
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

    if (pos_x>DIM || pos_y >DIM)
    {
      printf("\n\nValores inválidos\n\n");
      continue; // Próxima iteração do ciclo
    }

    pos_x--; pos_y--;  // Pois os índices do tab começam em 0 

    if (tabuleiro[pos_x][pos_y]==BRANCO)   // Posição livre no tabuleiro
    {
      tabuleiro[pos_x][pos_y] = ch = ((ch == '0') ? 'X' : '0');
      n_jogadas++;
      if (ganhou(tabuleiro, ch)) /* Basta testar o char corrente */
      {
        printf("Ganhou o jogador '%c'\n", ch);
        break;
      }
    }
    else
      printf("Posição já ocupada\nJogue Novamente!!!\n");

    if (n_jogadas==DIM*DIM)
    {
       printf("EMPATE!!!");
       break;
    }
  }

  mostrar(tabuleiro);
  return 0;
}
