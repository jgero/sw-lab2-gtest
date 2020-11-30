// Von generator/generator.exe generierte Datei!
#include <gtest/gtest.h>
#include "monatsbeitrag.h"

TEST(monatsbeitragTest, TF1) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Tischtennis"};
  EXPECT_EQ(mb.beitrag("Kind/Jugendlicher", abt), 12);
}

TEST(monatsbeitragTest, TF2) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Turnen", "Ballsport", "Fitness"};
  EXPECT_EQ(mb.beitrag("Kind/Jugendlicher", abt), 37);
}

TEST(monatsbeitragTest, TF3) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Tischtennis", "Turnen", "Fitness"};
  EXPECT_EQ(mb.beitrag("Erwachsener", abt), 44);
}

TEST(monatsbeitragTest, TF4) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Ballsport"};
  EXPECT_EQ(mb.beitrag("Erwachsener", abt), 27);
}

TEST(monatsbeitragTest, TF5) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Tischtennis", "Turnen", "Ballsport"};
  EXPECT_EQ(mb.beitrag("Ermaessigt", abt), 33);
}

TEST(monatsbeitragTest, TF6) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Fitness"};
  EXPECT_EQ(mb.beitrag("Ermaessigt", abt), 18);
}

TEST(monatsbeitragTest, TF7) {
  Monatsbeitrag mb;
  std::set<std::string> abt {};
  EXPECT_EQ(mb.beitrag("Passiv", abt), 20);
}
