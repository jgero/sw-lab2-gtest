#include "f.h"

bool f1(int x, int y, int z) {
  bool ergebnis = false;
  if(((x > 0) 
      && (y > 0)) 
     || (z > 0)) { 
    ergebnis = true;
  }
  return ergebnis;
}

bool f2(int x, int y, int z) {
  bool ergebnis = false;
  if (z > 0) {
    ergebnis = true;
  }
  else if(x > 0) {
    if(y > 0) {
      ergebnis = true;
    }
  }
  return ergebnis;
}


