#include <stdio.h>

#define TAXA_IVA1 5
#define TAXA_IVA2 23

#define Val_Iva(preco)  (((preco)<100) ? \
                         ((preco)*TAXA_IVA1/100.0) : \
                         ((preco)*TAXA_IVA2/100.0))

#define Val_Iva_Alt(preco)  \
  ((preco)*(((preco)<100) ? TAXA_IVA1 : TAXA_IVA2)/100.0)

int main(void)
{
  int x, y=2;
  printf("\nPreço=%f", Val_Iva(x+y));
  return 0;
}


