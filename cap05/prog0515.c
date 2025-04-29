#include <stdio.h>

void tiro(int x);
void liro(int x);


void tiro(int x)
{
  switch(x)
  {
    case 1: printf("Este teste e mesmo fácil\n");
    case 2: printf("Ai de quem diga o contrário...\n");
            return;
    case 3: printf("Estou no Tiro e x = %d\n",x);
            liro(x++);
            break;
            printf("Vou sair do tiro\n");
   default: printf("Entrei pelo default\n");
            liro(x);
  }
}

void liro(int x)
{
  switch(x)
  {
    case 2: return;
            printf("Olarailarilolela\n");
            break;
    case 3: printf("Eu percebo HIMALAIAS de C\n");
            break;
            printf("Sou mesmo Bom!!!\n");
            break;
    case 4: printf("Não percebo nada disto\n");
            liro(2);
            return;
   default: printf("Cá estou eu mais uma vez\n");
            tiro(x--);
  }
}

int main(void)
{
  tiro(1);
  puts("Prima <ENTER> para continuar\n"); scanf("%*c");

  tiro(3);
  puts("Prima <ENTER> para continuar\n"); scanf("%*c");

  liro(2);
  puts("Prima <ENTER> para continuar\n"); scanf("%*c");

  liro(4);
  puts("Prima <ENTER> para continuar\n"); scanf("%*c");

  liro(5);
  puts("Prima <ENTER> para continuar\n"); scanf("%*c");

  return 0;
}
