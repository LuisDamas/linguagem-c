#include <stdio.h>

int quadrado(int x)
{ return x*x; }

int dobro(int x)
{ return 2*x; }

int cubo(int x)
{ return quadrado(x)*x; }

/* Esta função tem dois parâmetros
    1) Um apontador para uma função que recebe como parâmetro um
       inteiro e devolve um inteiro como resultado
    2) Um inteiro a ser formatado pela função

   Depois coloca o resultado da execução da funcao(n) entre
   <<<| e |>>>
*/

void imprime_especial(int (*funcao)(int), int n)
{
  printf("<<<|%d|>>>\n", (*funcao)(n));
}

int main(void)
{
  int (*f)(int);
  f = quadrado;
  imprime_especial(f, 3);
  f = dobro;
  imprime_especial(f, 10);
  f = cubo;
  imprime_especial(f, 5);

  return 0;
}

