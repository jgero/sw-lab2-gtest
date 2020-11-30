#include "gtest/gtest.h"
#include "taxifahrt.h"

// Parameter: grundpreis, centProKm, strecke, nachtfahrt, gepaeck
constexpr std::size_t grundpreis = 350;  // Eurocent
constexpr std::size_t centProKm  = 210;  // Eurocent
// erwartet wird der Fahrpreis in Eurocent

TEST(Taxifahrt, TF1) {
  EXPECT_EQ(14510, fahrpreis(grundpreis, centProKm, 60, true, true));
}

TEST(Taxifahrt, TF2) {
  EXPECT_EQ(14210, fahrpreis(grundpreis, centProKm, 60, true, false));
}

TEST(Taxifahrt, TF3) {
  EXPECT_EQ(11990, fahrpreis(grundpreis, centProKm, 60, false, true));
}

TEST(Taxifahrt, TF4) {
  EXPECT_EQ(11690, fahrpreis(grundpreis, centProKm, 60, false, false));
}

TEST(Taxifahrt, TF5) {
  EXPECT_EQ(5480, fahrpreis(grundpreis, centProKm, 20, true, true));
}

TEST(Taxifahrt, TF6) {
  EXPECT_EQ(5180, fahrpreis(grundpreis, centProKm, 20, true, false));
}

TEST(Taxifahrt, TF7) {
  EXPECT_EQ(4640, fahrpreis(grundpreis, centProKm, 20, false, true));
}

TEST(Taxifahrt, TF8) {
  EXPECT_EQ(4340, fahrpreis(grundpreis, centProKm, 20, false, false));
}

TEST(Taxifahrt, TF9) {
  EXPECT_EQ(1910, fahrpreis(grundpreis, centProKm, 5, true, true));
}

TEST(Taxifahrt, TF10) {
  EXPECT_EQ(1610, fahrpreis(grundpreis, centProKm, 5, true, false));
}

TEST(Taxifahrt, TF11) {
  EXPECT_EQ(1700, fahrpreis(grundpreis, centProKm, 5, false, true));
}

TEST(Taxifahrt, TF12) {
  EXPECT_EQ(1400, fahrpreis(grundpreis, centProKm, 5, false, false));
}


