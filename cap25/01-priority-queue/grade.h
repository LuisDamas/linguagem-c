#pragma once
#define MAX_NAME 30

typedef struct {
  char name[MAX_NAME];
  double grade;
} Grade;

int compare_grades(const Grade *g1, const Grade *g2);
void grade_print(Grade grade);

