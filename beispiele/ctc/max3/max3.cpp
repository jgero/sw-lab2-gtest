#include "max3.h"

int max(int x, int y, int z) {
  int max = 0;
  if (x > z)
    max = x;
  if (y > x)
    max = y;
  if (z > y)
    max = z;
  return max;
}

