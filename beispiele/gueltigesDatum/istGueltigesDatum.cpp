#include "istGueltigesDatum.h"

bool istSchaltjahr(std::size_t jahr) {
  return (jahr % 4 == 0 && jahr % 100 != 0) || jahr % 400 == 0;
}

bool istGueltigesDatum(std::size_t tag, std::size_t monat, std::size_t jahr) {
  bool ergebnis = false;
  if( (monat >=1 && monat <=12)
      && (jahr > 1582        // 1582: Beginn des  gregorianischen Kalenders 
          && jahr < 2400)    // Plausibilitätskontrolle
      ) {
    std::size_t letzterTagImMonat = 29;              // nur Februar im Schaltjahr
    if (monat != 2 || !istSchaltjahr(jahr)) {        // sonst
      constexpr std::size_t tageImMonat[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      letzterTagImMonat = tageImMonat[monat - 1];
    }
    ergebnis = (tag >= 1 && tag <= letzterTagImMonat);
  }
  return ergebnis;
}
