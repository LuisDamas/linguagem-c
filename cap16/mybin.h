#pragma once
#include <limits.h>

typedef unsigned long long BIGINT;
typedef unsigned short int BOOLEAN;
typedef BIGINT BIT_INT;

#define TRUE  ((BOOLEAN) 1)
#define FALSE ((BOOLEAN) 0)
#define ZERO  ((BIT_INT) 0)
#define ONE   ((BIT_INT) 1)
#define BIGINT_SIZE (CHAR_BIT * sizeof(BIGINT))

BIT_INT getBit(BIGINT value, int n_bit);
void setBit(BIGINT *value, int n_bit, BIT_INT bit_value);

BIGINT applyOR(BIGINT value1, BIGINT value2);
BIGINT applyAND(BIGINT value1, BIGINT value2);
BIGINT applyXOR(BIGINT value1, BIGINT value2);
BIGINT applyNOT(BIGINT value);

