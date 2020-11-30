#include "StatistikDB.h"
#include <gtest/gtest.h>
#include <iostream>

namespace {
  class StatistikDBTest : public ::testing::Test {
  protected:
    StatistikDBTest()   // Testsetup
      : db("Studienstatistik.db"), 
        acts_dateiname("Studienstatistik.txt") {
      eingabe.open(acts_dateiname);
      // 1. Durchgang: Testdatenbank leeren und neu füllen
      db.leeren();
      db.fuellen(eingabe);
      eingabe.close();
      eingabe.clear();
    } 
    virtual ~StatistikDBTest() = default;
    StatistikDB db;
    std::string acts_dateiname;
    std::ifstream eingabe;
  };

  TEST_F(StatistikDBTest, VergleichDerTestFaelle) {
    // 2. Durchgang: Eigentlicher Test: Vergleich der Einträge
    eingabe.open(acts_dateiname);
    ueberspringeKopfteil(eingabe);
    std::size_t nr = 1;
    while(true)  {
      auto testfall = liesTestfall(eingabe);   
      // Nächste Zeile löschen! Fehler provozieren: test the test:
      if(nr ==3 || nr == 7) {testfall.at(1) = "murks";}
      if(testfall.size() > 0) {
        auto datenbankeintrag = db.liesTupel(nr);
        SCOPED_TRACE("Fehler in Tupel "  + std::to_string(nr));
        EXPECT_EQ(testfall, datenbankeintrag);
      }
      else {
        break;
      }
      ++nr;
    }
  }
}    // Namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

