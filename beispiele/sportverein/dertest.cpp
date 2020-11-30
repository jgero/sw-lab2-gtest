#include <gtest/gtest.h>
#include "monatsbeitrag.h"

TEST(monatsbeitragTest, TF1) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Tischtennis"};
  EXPECT_EQ(mb.beitrag("Kind/Jugendlicher", abt), 12);
}

TEST(monatsbeitragTest, TF2) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Turnen"};
  EXPECT_EQ(mb.beitrag("Erwachsener", abt), 29);
}

TEST(monatsbeitragTest, TF3) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Ballsport"};
  EXPECT_EQ(mb.beitrag("Ermaessigt", abt), 17);
}

TEST(monatsbeitragTest, TF4) {
  Monatsbeitrag mb;
  std::set<std::string> abt {"Fitness"};
  EXPECT_EQ(mb.beitrag("Erwachsener", abt), 28);
}

TEST(monatsbeitragTest, TF5_Passiv) {
  Monatsbeitrag mb; 
  EXPECT_EQ(mb.beitrag("Passiv"), 20);
}

TEST(monatsbeitragTest, TF6_Summe) {
  Monatsbeitrag mb; 
  std::set<std::string> abt {"Tischtennis", "Turnen", 
                             "Ballsport", "Fitness"};
  EXPECT_EQ(mb.beitrag("Kind/Jugendlicher", abt), 42);
}

TEST(monatsbeitragTest, TF7_PassivMitAbteilung) {
  Monatsbeitrag mb; 
  std::set<std::string> abt {"Fitness"};
  ASSERT_THROW(mb.beitrag("Passiv", abt), std::logic_error);
}

TEST(monatsbeitragTest, TF8_AktivOhneAbteilung) {
  Monatsbeitrag mb; 
  ASSERT_THROW(mb.beitrag("Erwachsener"), std::logic_error);
}


