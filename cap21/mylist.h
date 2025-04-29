#pragma once
#include <stdio.h>

#define MAX_STRING_SIZE 50
#define MAX_N_STRINGS 20000

typedef struct 
{
  int count;
  char word[MAX_N_STRINGS][MAX_STRING_SIZE];
} MYLIST;

void inic_list(MYLIST *ptr);
int load_list(MYLIST *ptr, FILE *fp);
