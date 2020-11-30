#ifndef KOMBINATIONSTEST_H
#define KOMBINATIONSTEST_H
#include <cassert> 
#include "fastbubblesorttest.h"

class Kombinationstest : public FastbubblesortTest<unsigned int> {
public:
  using FastbubblesortTest::FastbubblesortTest; // Konstruktor erben

  void execute() override {
    N = laenge;    // Anzahl der Kombinationen \tt{laenge\hoch{laenge}} berechnen:
    for(std::size_t i = 1u; i < laenge; ++i) {
      assert((N*laenge)/laenge == N);  // Überlaufprüfung
      N *= laenge;                     // Anzahl = \tt{laenge\hoch{laenge}}
    }
    // Schleife über alle Kombinationen
    for(std::size_t n = 0u; n < N; ++n) {
      auto zahl = n;
      for(auto& wert : folge) {   // Kombination erzeugen
        wert = 1 + zahl % laenge;
        zahl /= laenge;
      }
      auswertung();
    }
    zusammenfassung();
  }
};
#endif
