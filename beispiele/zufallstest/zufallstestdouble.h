#ifndef ZUFALLSTESTDOUBLE_H
#define ZUFALLSTESTDOUBLE_H
#include <random>
#include "fastbubblesorttest.h"

class Zufallstestdouble : public FastbubblesortTest<double> {
public:
  using FastbubblesortTest::FastbubblesortTest; // Konstruktor erben

  void execute() override {
    std::mt19937 generator;
    std::uniform_real_distribution<double> verteilung(0.0, 1.0);
    for(std::size_t i = 0u; i < N; ++i) {
      // Zufallswerte erzeugen
      for(auto& wert : folge) {
        wert = verteilung(generator);
      }
      auswertung();
    }
    zusammenfassung();
  }
};
#endif
