#include "pruefling.h"

pruefling::pruefling(double attribut_)
  : attribut(attribut_) {
}

double pruefling::attributquadrat() const {
  return attribut*attribut;
}
