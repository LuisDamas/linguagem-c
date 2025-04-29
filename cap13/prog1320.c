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
  int preco = 90;
  double preco2 = 1000;

  printf("Preco=%d Iva=%.2f\n", preco, Val_Iva(preco));
  printf("Preco=%d Iva=%.2f\n", preco, Val_Iva_Alt(preco));

  printf("Preco=%d Iva=%.2lf\n", preco, Val_Iva(preco2));
  printf("Preco=%d Iva=%.2lf\n", preco, Val_Iva_Alt(preco2));

  return 0;
}

