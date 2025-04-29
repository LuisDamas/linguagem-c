#pragma once
#define MAX_NAME 30

typedef struct person
{
  char first_name[MAX_NAME];
  char last_name[MAX_NAME];
  char gender;     // f or m
  int  birth_date; // yyyymmdd
} PERSON;

PERSON *person_create(char *first_name, 
                      char *last_name,
                      char gender,
                      int  year, int month, int day);

int compare_by_name(PERSON *p1, PERSON *p2);
int compare_by_age(PERSON *p1, PERSON *p2);
int compare_by_gender(PERSON *p1, PERSON *p2);
int compare_by_initials(PERSON *p1, PERSON *p2);

void person_print(PERSON *person, int add_NL);

void person_destroy(PERSON *person);

