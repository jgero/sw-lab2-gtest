#include "gtest/gtest.h"
#include <map>
#include <string>
#include "Fahrstuhlsteuerung.h"

namespace {
  // Diese Funktion dient dazu, den Programmcode 
  // der Testfälle zu verkürzen. Sie transformiert gleichzeitig
  // den internen Zifferncode in die Bezeichnung der Aktionen.
  const std::map<char, const std::string> zifferZuAktion
    { {'0', "NOP"}, {'1', "TO"}, {'2', "TS"}, {'3', "MS"}, 
      {'4', "MA"}, {'5', "TSMS"}, {'X', "X"} }; 
  std::string run(Fahrstuhlsteuerung& fst,
                   const std::string& eingabefolge) {
    std::string erg;
    for (auto input : eingabefolge) {
      erg += zifferZuAktion.at(fst.uebergang(input)) + " ";
    }
    erg.erase(--erg.end());  // letztes Leerzeichen wieder entfernen
    return erg;
  }
}

TEST(Zustand, TF1) {
  Fahrstuhlsteuerung fst;
  //           Eingabefolge   erwartete Ausgabefolge
  EXPECT_EQ( run(fst, "sb"), "TO TSMS");
}
TEST(Zustand, TF2) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "be"), "MS MA");
}
TEST(Zustand, TF3) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "sts"), "TO TS TO");
}
TEST(Zustand, TF4) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "ssb"), "TO NOP TSMS");
}
TEST(Zustand, TF5) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "sbe"), "TO TSMS MA");
}
TEST(Zustand, TF6) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "bse"), "MS NOP MA");
}
TEST(Zustand, TF7) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "bbe"), "MS NOP MA");
}
TEST(Zustand, TF8) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "bte"), "MS NOP MA");
}
TEST(Zustand, TF9) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "beb"), "MS MA TSMS");
}
TEST(Zustand, TF10) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "e"), "X");
}
TEST(Zustand, TF11) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "t"), "X");
}
TEST(Zustand, TF12) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "se"), "TO X");
}
TEST(Zustand, TF13_Uebergangsbaum) {
  Fahrstuhlsteuerung fst;
  EXPECT_EQ( run(fst, "beb"), "MS MA TSMS");
}


