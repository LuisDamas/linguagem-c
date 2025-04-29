#ifndef __PERSON_H__
#define __PERSON_H__

#define MAX_STR 30
typedef struct
{
  char firstName[MAX_STR];
  char lastName[MAX_STR];
  int  age;
} PERSON;

void print_person_direct(PERSON person);
void print_person_reverse(PERSON person);

void print_persons(PERSON arr[], int size, void (*print_person)(PERSON));

int compare_person_direct(const void* p1, const void* p2);
int compare_person_reverse(const void* p1, const void* p2);

#endif

