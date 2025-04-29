#include <stdio.h>
#include <limits.h>

// Mostra o conteúdo de um Byte em bits 
void showByte(unsigned char ch)
{
  for (int i=CHAR_BIT-1; i>=0; i--)
    printf("%d", (ch >>i ) & 1);
}

int main(void)
{
  unsigned char ch = 0;

  for (int i=0; i<CHAR_BIT; i++)
  { ch = ch + (1 <<i );
    printf("Index: %d \tDec.: %3d\tBin.: ", i, ch);
    showByte(ch);
    putchar('\n');
  }

  return 0;
}

