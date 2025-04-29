#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 3

void transpose(int v[MAX][MAX])
{
  for(int row=0; row<MAX; row++)
    for(int col=row+1; col<MAX; col++)
    {
      int tmp = v[row][col];
      v[row][col] = v[col][row];
      v[col][row] = tmp;
    }
}

void print(int v[MAX][MAX])
{
  for(int row=0; row<MAX; row++)
  {
    for(int col=0; col<MAX; col++)
      printf(" Mat[%d][%d] = %d\n", row, col, v[row][col]);
    putchar('\n');
  }
}

int main()
{
  int mat[MAX][MAX] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                      };

  puts("Matriz original");
  print(mat);

  transpose(mat);
  puts("Matriz transposta");
  print(mat);

  return 0;
}
