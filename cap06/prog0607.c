#include <stdio.h>
#define DIM 3

int main(void)
{
  char tabuleiro[DIM][DIM]= {{' ',' ',' '},
                             {' ',' ',' '},
                             {' ',' ',' '}
                            };
  tabuleiro[0][0] = 'X';
  tabuleiro[1][1] = 'X';
  tabuleiro[0][2] = '0';
  tabuleiro[2][2] = '0';

  for (int linha=0; linha<DIM; linha++)
  {
    for (int coluna=0; coluna<DIM; coluna++)
      printf(" %c %c", tabuleiro[linha][coluna], coluna==DIM-1 ? ' ' : '|');

    if (linha!=DIM-1) 
      printf("\n-----------\n");
  }
  putchar('\n');
  return 0;
}

