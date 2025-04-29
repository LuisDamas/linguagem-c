#pragma once

typedef struct person
{
  char *first_name;
  char *last_name;
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
int compare_by_seq(PERSON *p1, PERSON *p2);

void person_print(PERSON *person);

void person_destroy(PERSON *person);

