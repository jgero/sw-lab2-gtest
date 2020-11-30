#include "taxifahrt.h"

// gibt Preis in Eurocent zurück
int fahrpreis(int grundpreis,                  // Eurocent
              int centProKm,
              int streckeInKm,
              bool nachtfahrt,
              bool gepaeck) {
  double preis = grundpreis + centProKm * streckeInKm;
  if(streckeInKm > 50) {
    preis *= 0.9;                              // Rabatt 10\%
  } else if(streckeInKm > 10) {
    preis *= 0.95;                             // Rabatt 5\%
  }
  if(nachtfahrt) {
    preis *= 1.2;                              // Zuschlag 20\%
  }
  if(gepaeck) {
    preis += 300;                              // Zuschlag 3 Euro
  }
  return static_cast<int>(preis + 0.5);        // Rundung
}
