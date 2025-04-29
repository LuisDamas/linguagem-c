#include <stdio.h>
#include <math.h>

typedef struct 
{ double x, y; } Coord;

double get_distance(Coord c)
{
  return sqrt(pow(c.x, 2.0)+pow(c.y, 2.0));
}

int main(void)
{
  Coord coord = {1,1};

  printf("%f\n", get_distance(coord));
  return 0;
}
