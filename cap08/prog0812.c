#include <stdio.h>
#include <string.h>
#define MAX_STR 50

char *my_strstr(char *str1, char *str2)
{
  int len_search = strlen(str1)-strlen(str2);
  int len_str2 = strlen(str2);

  for (int i=0 ; i<=len_search ; i++)
    if (strncmp(str1+i, str2, len_str2)==0)
      return str1+i;
  return NULL;
}

int main(void)
{
  char str[MAX_STR], search[MAX_STR];
  char *ptr_found=NULL;

  puts(">>> Termine o programa com strings vazias <<<");

  while (1)
  {
     printf("String principal : "); gets(str);
     printf("String a procurar: "); gets(search);
     if (str[0]=='\0' && search[0]=='\0')
       break;

     if ((ptr_found=my_strstr(str, search))==NULL)
       printf("\n\nString não encontrada\n\n");
     else
       printf("String [%s] encontrada em [%s]\n\n", search, ptr_found);
  }

  return 0;
}
