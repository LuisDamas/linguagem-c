#include <stdio.h>

float min_arr(float arr[], int n)
{
  float res = arr[0];
  for (int i=1; i<n; i++)
    if (arr[i] < res)
      res = arr[i];
  return res;
}

float max_arr(float arr[], int n)
{
  float res = arr[0];
  for (int i=1; i<n; i++)
    if (arr[i] > res)
      res = arr[i];
  return res;
}

float avg_arr(float arr[], int n)
{
  float res = 0;
  for (int i=0; i<n; i++)
    res += arr[i];
  return res/n;
}

int main(void)
{
  float v[] = {3.14, 5.16, 1.23, 9.99, 0.13};
  int array_size = sizeof(v) / sizeof(v[0]);

  float (*func)(float*, int);

  printf("Min Array: %.2f\n", min_arr(v, array_size));
  printf("Max Array: %.2f\n", max_arr(v, array_size));
  printf("Avg Array: %.2f\n", avg_arr(v, array_size));

  puts("----------------");

  func = min_arr;
  printf("Min Array: %.2f\n", func(v, array_size));
  func = max_arr;
  printf("Max Array: %.2f\n", func(v, array_size));
  func = avg_arr;
  printf("Avg Array: %.2f\n", func(v, array_size));

  return 0;
}
