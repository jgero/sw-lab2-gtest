#include "gtest/gtest.h"
#include "taxifahrt.h"

// Parameter: grundpreis, centProKm, strecke, nachtfahrt, gepaeck
constexpr std::size_t grundpreis = 350;  // Eurocent
constexpr std::size_t centProKm  = 210;  // Eurocent
// erwartet wird der Fahrpreis in Eurocent

TEST(Taxifahrt, TF1) {
  EXPECT_EQ(14286, fahrpreis(grundpreis, centProKm, 60, true, true));
}

TEST(Taxifahrt, TF2) {
  EXPECT_EQ(13986, fahrpreis(grundpreis, centProKm, 60, true, false));
}

TEST(Taxifahrt, TF3) {
  EXPECT_EQ(11955, fahrpreis(grundpreis, centProKm, 60, false, true));
}

TEST(Taxifahrt, TF4) {
  EXPECT_EQ(11655, fahrpreis(grundpreis, centProKm, 60, false, false));
}

TEST(Taxifahrt, TF5) {
  EXPECT_EQ(5487, fahrpreis(grundpreis, centProKm, 20, true, true));
}

TEST(Taxifahrt, TF6) {
  EXPECT_EQ(5187, fahrpreis(grundpreis, centProKm, 20, true, false));
}

TEST(Taxifahrt, TF7) {
  EXPECT_EQ(4623, fahrpreis(grundpreis, centProKm, 20, false, true));
}

TEST(Taxifahrt, TF8) {
  EXPECT_EQ(4323, fahrpreis(grundpreis, centProKm, 20, false, false));
}

TEST(Taxifahrt, TF9) {
  EXPECT_EQ(1980, fahrpreis(grundpreis, centProKm, 5, true, true));
}

TEST(Taxifahrt, TF10) {
  EXPECT_EQ(1680, fahrpreis(grundpreis, centProKm, 5, true, false));
}

TEST(Taxifahrt, TF11) {
  EXPECT_EQ(1700, fahrpreis(grundpreis, centProKm, 5, false, true));
}

TEST(Taxifahrt, TF12) {
  EXPECT_EQ(1400, fahrpreis(grundpreis, centProKm, 5, false, false));
}


