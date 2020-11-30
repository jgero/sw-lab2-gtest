#include "undoder.h"

bool undoder(int x, int y, int z) {
  bool ergebnis = false;
  if(((x > 0) && (y > 0)) || (z > 0)) { 
    ergebnis = true;
  }
  return ergebnis;
}
