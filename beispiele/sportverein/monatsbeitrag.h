#ifndef MONATSBEITRAG_H
#define MONATSBEITRAG_H
#include <cstddef>
#include <map>
#include <stdexcept>
#include <string>
#include <set>
#include <utility>

class Monatsbeitrag {
public:
  Monatsbeitrag()
  /* Der Kürze wegen sind die Basisdaten hier fest einprogrammiert.
     Normalerweise würden sie durch Einlesen einer Konfigurationsdatei
     oder Datenbank initialisiert werden.
     Die Preise sind der Einfachheit halber in ganzen Euro.
  */
      : dieAbteilungen{{"Tischtennis", 5},
                       {"Turnen", 11},
                       {"Ballsport", 9},
                       {"Fitness", 10}},
                                               // aktiv, Grundbeitrag
        mitgliedsstatus{{"Kind/Jugendlicher", {true, 7}},
                       {"Erwachsener", {true, 18}},
                       {"Ermaessigt", {true, 8}},
                       {"Passiv", {false, 20}}} {
        }

  // Die eigentliche Funktion zur Beitragsberechnung
  std::size_t beitrag(const std::string& status,
                      const std::set<std::string>& abteilungen =
                            std::set<std::string>()) const {
    // Prüfung auf bestimmte Fehler
    bool aktiv = mitgliedsstatus.at(status).first;
    if(aktiv && abteilungen.size() == 0) {
      throw std::logic_error("Aktiv ohne Abteilungszuordnung!");
    }
    if(!aktiv && abteilungen.size() > 0) {
      throw std::logic_error("Passiv mit Abteilungszuordnung!");
    }
    // Preisberechnung
    auto preis = mitgliedsstatus.at(status).second; // Grundpreis
    for (const auto& abt : abteilungen) {            // Zusatzpreis(e)
      preis += dieAbteilungen.at(abt);
    }
    return preis;
  }
private:
                 // < Name,     Zusatzpreis >
  const std::map<std::string, std::size_t> dieAbteilungen;
                 // < Name,     <aktiv ja/nein, Grundpreis> >
  const std::map<std::string, std::pair<bool, std::size_t>>
                mitgliedsstatus;
};
#endif
