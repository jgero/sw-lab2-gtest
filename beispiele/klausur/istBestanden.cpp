#include "istBestanden.h"
#include <stdexcept>
#include <string>

bool istBestanden(int punkte) {
  if (punkte < 0) {
    throw std::invalid_argument("zu kleine Punktzahl: " 
                            + std::to_string(punkte));
  }
  if (punkte > 100) {
    throw std::invalid_argument("zu hohe Punktzahl: "
                            + std::to_string(punkte));
  }
  return punkte >= 50;
}
