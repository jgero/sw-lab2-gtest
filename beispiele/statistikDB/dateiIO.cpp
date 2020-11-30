#include "dateiIO.h"
#include "../util/split.h" // String mit Trennzeichen in einen Vector aufsplitten

void ueberspringeKopfteil(std::ifstream& datei) {
  std::string zeile;
  bool testset_gefunden = false;
  while(datei.good() && !testset_gefunden) {
    std::getline(datei, zeile);
    if(zeile == "[Test Set]") { 
      testset_gefunden = true;
      while(datei.good()) {  // Kommentar überlesen
        std::getline(datei, zeile);
        if(zeile.length() > 2 && zeile[0] != '-')
          break;
      }
    }
  }
}

std::vector<std::string> liesTestfall(std::ifstream& datei) {
  std::vector<std::string> ergebnis;
  if(datei.good()) {
    std::string zeile;
    std::getline(datei, zeile);
    if(zeile.length() > 1) {
      ergebnis = split(zeile, ",");
    }
  }
  return ergebnis;
}
