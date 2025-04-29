#ifndef __MYDATE_H__
#define __MYDATE_H__

struct s_date
{
  int day, month, year;
};
typedef struct s_date* date_type;

date_type date_create(int day, int month, int year);
void date_destroy(date_type date);

int is_leap_year(int year);
void date_print(date_type date);
date_type date_add1(date_type date);
int date_compare(date_type d1, date_type d2);

#endif
