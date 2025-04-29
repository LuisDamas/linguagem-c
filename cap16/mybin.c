#include <stdio.h>
#include <stdlib.h>
#include "mybin.h"

BIT_INT getBit(BIGINT value, int n_bit)
{
  return (value >> n_bit) & ONE;
}

void setBit(BIGINT *value, int n_bit, BIT_INT bit_value)
{
  BIGINT mask = ONE << n_bit;

  if (bit_value == ZERO)
    *value &= (~mask);
  else // ONE
    *value |= mask;
}

BIGINT add1(BIGINT value)
{
  BIGINT res = value;
  BIGINT e_vai = ONE;  // Adicionar 1 (como se fosse e vai um)

  for (int n_bit = 0; n_bit < BIGINT_SIZE; n_bit++)
  {
    if (e_vai==ZERO) break; // o número está completo

    BIT_INT cur_bit_value = getBit(value, n_bit);

    if (cur_bit_value==ZERO)
      setBit(&res, n_bit, ONE);
    else
      setBit(&res, n_bit, ZERO);
    e_vai = (cur_bit_value == ONE);

  }

  return res;
}

// Função local genérica para aplicar os operadores binários bit-a-bit
static BIGINT applyOperation(BIGINT value1, BIGINT value2, char op)
{
  BIGINT res=0;
  BIT_INT bit_value;

  for(int n_bit=0; n_bit<BIGINT_SIZE; n_bit++)
  {
     switch(op)
     {
       case '|' : bit_value = getBit(value1, n_bit) | getBit(value2, n_bit); break;
       case '&' : bit_value = getBit(value1, n_bit) & getBit(value2, n_bit); break;
       case '^' : bit_value = getBit(value1, n_bit) ^ getBit(value2, n_bit); break;
     }
     setBit(&res, n_bit, bit_value);
  }

  return res;
}


BIGINT applyOR(BIGINT value1, BIGINT value2)
{
  return applyOperation(value1, value2, '|');
}

BIGINT applyAND(BIGINT value1, BIGINT value2)
{
  return applyOperation(value1, value2, '&');
}

BIGINT applyXOR(BIGINT value1, BIGINT value2)
{
  return applyOperation(value1, value2, '^');
}

BIGINT applyNOT(BIGINT value)
{
  return applyXOR(value, 0xFFFFFFFFFFFFFFFFll);
}

void printBinary(BIGINT value)
{
  for (int i=CHAR_BIT*sizeof(value)-1; i>=0; i--)
  {
    putchar(getBit(value, i) + '0');
    if (i%CHAR_BIT==0)
      putchar(' ');
    else
      if (i%(CHAR_BIT/2)==0) putchar('-');
  }
}


int main(void)
{

  BIGINT value = 0;
  printf("Imprimir o valor inicial (ZERO)\n");
  printBinary(value); printf("\n\n");

  printf("Colocar a 1 (ONE) o MSB e o LSB\n");
  setBit(&value, 0, ONE); 
  setBit(&value, BIGINT_SIZE-1, ONE);
  printBinary(value); printf("\n\n");

  printf("Colocar a 0 (ZERO) o MSB e o LSB\n");
  setBit(&value, 0, ZERO);
  setBit(&value, BIGINT_SIZE-1, ZERO);
  printBinary(value); printf("\n\n");

  printf("Colocar todos os bits em posições par a 1\n");
  for (int i=0; i<BIGINT_SIZE; i+=2)
    setBit(&value, i, ONE);
  printBinary(value); printf("\n\n");

  printf("Colocar apenas os bits em posições impar a 1\n");
  for (int i=0; i<BIGINT_SIZE; i++)
    setBit(&value, i, i%2==1? ONE : ZERO);
  printBinary(value); printf("\n\n");

  BIGINT value2 = 0;
  printf("Realizar 10 somas de 1, a partir do número 0\n");
  printBinary(value2); printf("\n");
  for (int i=1; i<=10; i++)
  {
    value2 = add1(value2);
    printBinary(value2); printf("\n");
  }
  printf("\n");

  value = (long long) 0x2a7fc122d16a9e0c; // um valor qualquer
  BIGINT mask =       0xFF00F00F0FF000FF;

  printBinary(value); printf("  value\n");
  printBinary(mask);  printf("  mask\n");
  printBinary(applyOR(value, mask)); printf("  value OR mask\n\n");

  printBinary(value); printf("  value\n");
  printBinary(mask);  printf("  mask\n");
  printBinary(applyAND(value, mask)); printf("  value AND mask\n\n");

  printBinary(value); printf("  value\n");
  printBinary(mask);  printf("  mask\n");
  printBinary(applyXOR(value, mask)); printf("  value XOR mask\n\n");

  printBinary(value); printf("  value\n");
  printBinary(applyNOT(value)); printf("  NOT value\n");

  return 0;
}
