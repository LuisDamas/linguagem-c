#include <stdio.h>
#include <ctype.h>
#include <limits.h>

void printBinary(unsigned char ch)
{
  for (int i=CHAR_BIT-1; i>=0; i--)
    putchar(ch & (1 << i) ? '1' : '0');
}

void dumpToBin(void *ptr, size_t size)
{
  unsigned char ch;
  while (size-->0)
  { ch = *((char*) ptr);
    printBinary(ch);
    printf(" [%c] [%03u]", isprint(ch)? ch : '?', ch);
    printf(" %p\n", ptr++);
  }
  putchar('\n');
}

int main()
{
  char ch = 'A';
  int n = 0xA0B1C2D3;
  char msg[]="Hello";
  struct person {char nome[4]; int idade;} p = {"Ana", 35};

  dumpToBin(&ch, sizeof(ch));
  dumpToBin(&n,  sizeof(n));
  dumpToBin(msg, sizeof(msg));
  dumpToBin(&p,  sizeof(p));

  return 0;
}
