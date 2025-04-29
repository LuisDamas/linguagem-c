#include <stdio.h>
#include <string.h>

char *strrcpy(char *dest, char *orig)
{
  for (int len = strlen(orig); len>=0 ; len--)
    dest[len]=orig[len];
  return dest;
}

char *str_ins(char *dest, char *orig)
{
  strrcpy(dest+strlen(orig), dest);
  memcpy(dest, orig, strlen(orig));
  return dest;
}

int main(void)
{
  char s[100] = "Gama";

  str_ins(s, "Beta");
  printf("%s\n", s);		// BetaGama

  str_ins(s, "Alfa");
  printf("%s\n", s);		// AlfaBetaGama

  return 0;
}
