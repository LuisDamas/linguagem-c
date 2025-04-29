#include<stdio.h>

void before_main();
void before_end();
void any_function();

#pragma startup before_main
#pragma exit before_end

void before_main()
{
  printf("Running function before_main()\n");
}

void before_end()
{
  printf("Running function end_main()\n");
}

void any_function()
{
  printf("\t\tRunning function any_function()\n");
}

int main() 
{
  printf("\tStarting function main()\n"); 
  any_function();
  printf("\tEnding function main()\n");

  return 0;
}
