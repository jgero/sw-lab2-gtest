#ifndef ZUFALLSTEST_H
#define ZUFALLSTEST_H
#include <random>
#include "fastbubblesorttest.h"

class Zufallstest : public FastbubblesortTest<unsigned int> {
public:
  using FastbubblesortTest::FastbubblesortTest; // Konstruktor erben
  void execute() override {
    std::mt19937 generator;       // einer der C++-Zufallszahlengeneratoren
    std::uniform_int_distribution<unsigned int> verteilung(1, laenge);
    for(std::size_t i = 0u; i < N; ++i) {  // N Folgen untersuchen     
      for(auto& wert : folge) {      // Zufallswerte für jede Folge  erzeugen
        wert = verteilung(generator);
      }
      auswertung();
    }
    zusammenfassung();
  }
};
#endif
