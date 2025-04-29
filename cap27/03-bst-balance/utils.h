#pragma once
#include "bst.h"

#define STEP 2
#define RIGHT_SEP "/"
#define LEFT_SEP "\\"

void pretty_print(NODE *root);
void bst_balance(NODE **ptrToRoot);
