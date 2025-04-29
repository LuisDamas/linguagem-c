#include <stdio.h>

int main(void)
{
  int x = 5;
  int *ptr_x;         /* Apontador para x */
  int **ptr_ptr_x;    /* Apontador para o Apontador de x */

  /* Inicialização dos apontadores */
  ptr_x = &x;
  ptr_ptr_x = &ptr_x;

  printf("x=%d &x=%p\n", x, &x);
  printf("*ptr_x=%d ptr_x=%p &ptr_x=%p\n", 
          *ptr_x, ptr_x, &ptr_x);
  printf("**ptr_ptr_x=%d *ptr_ptr_x=%p ptr_ptr_x=%p &ptr_ptr_x=%p\n",
          **ptr_ptr_x, *ptr_ptr_x, ptr_ptr_x, &ptr_ptr_x);
  return 0;
}

