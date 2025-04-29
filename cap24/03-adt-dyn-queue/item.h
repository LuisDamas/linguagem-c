#pragma once

typedef struct Item* ITEM;

ITEM item_create(char*brand, char*model, 
                 int year, int month, int day);
void item_show(ITEM ptr);
void item_destroy(ITEM q);
