#include <stdio.h>

int main(void)
{
  for (int tabuada=1 ; tabuada<=5 ; tabuada=tabuada+1)
  {
    for (int n_linha=1 ; n_linha<=10 ; n_linha=n_linha+1)
      printf("%2d * %2d = %2d\n", tabuada, n_linha, tabuada*n_linha);

    if (tabuada != 5) /* para não parar na última */
    {
      printf("Prima <ENTER> para continuar ...");
      getchar();
    }
  }
  return 0;
}



