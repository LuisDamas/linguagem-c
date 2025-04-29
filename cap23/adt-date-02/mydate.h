#ifndef __MYDATE_H__
#define __MYDATE_H__

typedef struct s_date* date_type;

date_type date_create(int day, int month, int year);
void date_destroy(date_type date);

void date_print(date_type date);
date_type date_add1(date_type date);
int date_compare(date_type d1, date_type d2);

#endif
