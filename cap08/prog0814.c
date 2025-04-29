#include <stdio.h>
#include <string.h>

int main(void)
{
  int v[5] = {10, 20, 30, 40, 50}; // Array com 5 inteiros
  int *pv;                         // Pointer para inteiro
  int **ppv;                       // Pointer para Pointer para inteiro

  pv = v;
  ppv = &pv;

  printf("%d %d %d\n", v[0]     , *pv       , **ppv);
  printf("%d %d %d\n", v[1]     , *(pv+1)   , *((*ppv)+1));
  printf("%d %d %d\n", v[2]     , *(pv+3)   , *((*ppv)+4));
  printf("%d %d %d\n", v[0]-1   , *(pv+1)-1 , *((*ppv)+2)-1);

  return 0;
}


