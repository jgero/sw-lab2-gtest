#include "rabatt.h"
#include <algorithm>      // std::max()
#include <stdexcept>

std::size_t rabatt(std::size_t rechnungsbetrag,
                   std::size_t stunde, std::size_t minute) {
  // Prüfen der Vorbedingungen
  // (Repräsentanten ungültiger Äquivalenzklassen)
  if(rechnungsbetrag > 1000000)                           // uAeK11
    throw std::invalid_argument("Rechnungsbetrag zu hoch");
  if(rechnungsbetrag == 0)                                // uAeK12
    throw std::invalid_argument("Rechnungsbetrag ist 0");
  if((stunde == 20 && minute > 0)                         // uAeK21
     ||  (stunde > 20 && stunde < 24))
    throw std::invalid_argument("Uhrzeit zu spät");
  if(stunde < 8)                                          // uAeK22
    throw std::invalid_argument("Uhrzeit zu früh");
  if(stunde >= 24)                                        // uAeK23
    throw std::invalid_argument("Stunde >= 24");
   
  // Prüfung von Repräsentanten gültiger Äquivalenzklassen  gAeK3x (x=1..5)
  // (eigentliche Rabattberechnung)
  std::size_t rabatt1 = rechnungsbetrag >= 15000 ? 1000 : 0;
  std::size_t rabatt2 = 0;
  if((stunde == 10 && minute == 0) || stunde < 10) {
    double temp = 0.05 * rechnungsbetrag;
    rabatt2 = static_cast<std::size_t>(temp + 0.5); // Rundung
  }
  return std::max(rabatt1, rabatt2);
}
