#include <stdio.h>
#include <string.h>
#include "person.h"

void print_person_direct(PERSON person)
{
  printf("%s %s, %d years\n", person.firstName, person.lastName, person.age);
}

void print_person_reverse(PERSON person)
{
  printf("%s, %s (%d)\n", person.lastName, person.firstName, person.age);
}


void print_persons(PERSON *arr, int size, void(*print)(PERSON))
{
  for (int i=0; i<size; i++)
    print(arr[i]);
}

int compare_person_direct(const void* p1, const void* p2)
{
  PERSON *ptr1 = (PERSON *) p1;
  PERSON *ptr2 = (PERSON *) p2;

  int res = strcmp(ptr1->firstName, ptr2->firstName);
  if (res!=0) return res;

  if ((res=strcmp(ptr1->lastName, ptr2->lastName))!=0) 
    return res;
 
  return ptr1->age - ptr2->age; 
}

int compare_person_reverse(const void* p1, const void* p2)
{
  PERSON *ptr1 = (PERSON *) p1;
  PERSON *ptr2 = (PERSON *) p2;

  int res = strcmp(ptr1->lastName, ptr2->lastName);
  if (res!=0) return res;

  if ((res=strcmp(ptr1->firstName, ptr2->firstName))!=0) 
    return res;
 
  return ptr1->age - ptr2->age; 
}
