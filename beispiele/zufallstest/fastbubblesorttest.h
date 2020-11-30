#ifndef FASTBUBBLESORTTEST_H
#define FASTBUBBLESORTTEST_H
#include <algorithm>
#include <iostream> 
#include "fastbubblesort.t"

template<typename T>
class FastbubblesortTest {
using Container = std::vector<unsigned int>;
public:
  FastbubblesortTest(std::size_t L, std::size_t anz = 0) 
    : laenge(L), folge(L), eingabe(L), referenz(L), N(anz) {
  }

  virtual void execute() = 0;   //von den abgeleiteten Klassen zu 
                                // implementieren

  virtual ~FastbubblesortTest() = default;

  void zusammenfassung() const {
    std::cout << fehlerzahl << " Ergebnisse von " << N
              << " sind falsch, d.h. " 
               << 100.0*fehlerzahl/N << "%\n";
  }

  void auswertung() {
    eingabe = folge;  // Eingabewerte sichern
    // korrektes Ergebnis mit Standardfunktion erzeugen:
    referenz = folge;
    std::sort(referenz.begin(), referenz.end());
    // Folge mit zu testender Funktion sortieren und vergleichen:
    fastbubblesort(folge); 
    if(folge != referenz) {
      ++fehlerzahl;
      std::cout << "Eingabewerte: ";   show(eingabe);
      std::cout << "  erwartet: ";     show(referenz);
      std::cout << "  tatsächlich: ";  show(folge);
      std::cout << '\n';
    }
  }

  void show(const Container& cont) {
    for(auto w : cont) {
      std::cout << w << ' ';
    }
  }
protected:
  std::size_t laenge;
  Container folge;
  Container eingabe;
  Container referenz;
  std::size_t fehlerzahl = 0;
  std::size_t N;
};
#endif

