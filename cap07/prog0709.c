#include <stdio.h>
#include <string.h>

int isStrPalindrome(char *s)
{
  int i,j;
  for (i=0, j=strlen(s)-1 ; i<j ; i++, j--)
    if (s[i]!=s[j]) /* Se os carateres não forem iguais */
      return 0;     /* Não é capicua                    */
  return 1;
}

int main(void)
{
  char str[30];

  strcpy(str, "");
  printf("[%s] é capicua? %s\n", str,
               isStrPalindrome(str) ? "Sim" : "Não");

  strcpy(str, "m");
  printf("[%s] é capicua? %s\n", str,
               isStrPalindrome(str) ? "Sim" : "Não");

  strcpy(str, "ba");
  printf("[%s] é capicua? %s\n", str,
               isStrPalindrome(str) ? "Sim" : "Não");

  strcpy(str, "matam");
  printf("[%s] é capicua? %s\n", str,
               isStrPalindrome(str) ? "Sim" : "Não");

  strcpy(str, "assa");
  printf("[%s] é capicua? %s\n", str,
               isStrPalindrome(str) ? "Sim" : "Não");

  strcpy(str, "capicua");
  printf("[%s] é capicua? %s\n", str,
               isStrPalindrome(str) ? "Sim" : "Não");

  return 0;
}
