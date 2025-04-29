#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * StrDelUpper(char *s)
{ char *prim, *ptr;
  prim = ptr = s;

  while (*s) /* Equivalente a while (*s!='\0') */
  {
     if (!isupper(*s))
       *ptr++=*s;
     s++;
  }
  *ptr='\0';

  return prim;
}

char * StrDelStr(char *s1, char *s2)
{
 char *loc = strstr(s1,s2);
 if (loc!=NULL) 	/* Se s2 existir em s1 */
   strcpy(loc, loc+strlen(s2));

 return s1;
}

int main(void)
{

  char mix[] = "Alfa_BETA_GaMa?~deltA";
  char s[] = "O rato roeu a rolha da garrafa de rum do rei da Rússia";

  printf("Apagar maiúsculas em [%s]\n", mix);
  printf("[%s]\n\n", StrDelUpper(mix));

  printf("Apagar [xy]: %s\n", StrDelStr(s, "xy"));
  printf("Apagar [ra]: %s\n", StrDelStr(s, "ra"));

  return 0;
}

