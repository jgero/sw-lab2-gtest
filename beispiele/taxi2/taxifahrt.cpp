#include "taxifahrt.h"
#include <cmath>

// gibt Preis in Eurocent zurück
int fahrpreis(int grundpreisInCent, 
              int preisInCentProKm,
              int streckeInKm,
              bool nachtfahrt,
              bool gepaeckVorhanden) {
  int basispreis = preisInCentProKm * streckeInKm;
  int rabatt = 0;
  if(streckeInKm > 50) {
    rabatt = std::round(0.1 * basispreis);    // Rabatt 10\%, gerundet
  } else if(streckeInKm > 10) {
    rabatt = std::round(0.05 * basispreis);   // Rabatt 5\%, gerundet
  }
  int zuschlag = 0;
  if(nachtfahrt) {
    zuschlag = std::round(0.2 * basispreis);  // Zuschlag 20\%, gerundet
  }
  if(gepaeckVorhanden) {
    zuschlag += 300;                       // Cent Zuschlag für Gepäck
  }
  return  grundpreisInCent + basispreis + zuschlag - rabatt;
}
