#include <stdio.h>
#define toupper(ch) ((ch)>='a' && (ch)<='z' ? (ch) + 'A' - 'a' : (ch))

#define FIRST 'A'
#define LAST 'Z'

int main(void)
{
  int ch=65; /* ASCII do 'A' */
  printf("%c %c", toupper(FIRST+2),toupper(LAST+'a'-ch));
  return 0;
}

