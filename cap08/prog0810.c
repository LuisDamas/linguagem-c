#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[] = "Exame";
  char **pps;  // Pointer para Pointer para char
  char *ps;    // Pointer para char

  ps = s;      // ou ps = &s[0]
  pps = &ps;

  printf("%c %c %c\n"   , s[0]     , *ps       , **pps);
  printf("%c %c %c\n"   , s[1]     , *(ps+2)   , *((*pps)+3));
  printf("%c %c %c\n"   , *(s+4)   , ps[4]     , (*pps)[4]);
  printf("%lu %lu %lu\n", strlen(s), strlen(ps), strlen(*pps));

  return 0;
}
