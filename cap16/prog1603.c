#include <stdio.h>
#include <limits.h>

int main(void)
{
 unsigned char mask = 0xFF & 0x80; // Máscara para obter o bit mais à esquerda do byte
 int n_bits = CHAR_BIT;

 for (int i=0; i<n_bits; i++)
   printf("Index=%d: valor: %3d\n", n_bits-i-1, mask >> i);

  return 0;
}

