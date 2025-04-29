#include <stdio.h>
#include <string.h>
#include "grade.h"

int compare_grades(const Grade *g1, const Grade *g2)
{
  double cmp = g1->grade - g2->grade;
  if (cmp<0) return -1;
  if (cmp>0) return 1;

  return strcmp(g1->name, g2->name);
}

void grade_print(Grade grade)
{
  printf("[%s %.2lf]", grade.name, grade.grade);
}
