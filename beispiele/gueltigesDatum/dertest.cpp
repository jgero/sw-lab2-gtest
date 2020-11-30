#include <gtest/gtest.h>
#include "istGueltigesDatum.h"

// gültige Äquivalenzklassen
TEST(istGueltigesDatumTest, gAeK1_normal) {
  EXPECT_TRUE(istGueltigesDatum(15, 3, 2016));
}

TEST(istGueltigesDatumTest, gAeK2_30) {
  EXPECT_TRUE(istGueltigesDatum(30, 9, 2018));
}

TEST(istGueltigesDatumTest, gAeK3_31) {
  EXPECT_TRUE(istGueltigesDatum(31, 8, 2017));
}

TEST(istGueltigesDatumTest, gAeK4_29_Schaltjahr) {
  EXPECT_TRUE(istGueltigesDatum(29, 2, 2016));
}

TEST(istGueltigesDatumTest, gAeK5_29_Schaltjahr400) {
  EXPECT_TRUE(istGueltigesDatum(29, 2, 2000));
}

// Äquivalenzklassen mit ungültigen Werten
TEST(istGueltigesDatumTest, uAeK1_Tag0) {
  EXPECT_FALSE(istGueltigesDatum(0, 5, 2019));
}

TEST(istGueltigesDatumTest, uAeK2_TagZuGross) {
  EXPECT_FALSE(istGueltigesDatum(1000, 5, 2019));
}

TEST(istGueltigesDatumTest, uAeK3_Monat0) {
  EXPECT_FALSE(istGueltigesDatum(1, 0, 1899));
}

TEST(istGueltigesDatumTest, uAeK4_MonatZuGross) {
  EXPECT_FALSE(istGueltigesDatum(1, 13, 1899));
}

TEST(istGueltigesDatumTest, uAeK5_JahrZuKlein) {
  EXPECT_FALSE(istGueltigesDatum(1, 12, 1580));
}

TEST(istGueltigesDatumTest, uAeK6_JahrZuGross) {
  EXPECT_FALSE(istGueltigesDatum(1, 12, 3580));
}

TEST(istGueltigesDatumTest, uAeK7_30_Februar) {
  EXPECT_FALSE(istGueltigesDatum(30, 2, 1752));
}

TEST(istGueltigesDatumTest, uAeK8_31_April) {
  EXPECT_FALSE(istGueltigesDatum(31, 4, 2087));
}

TEST(istGueltigesDatumTest, uAeK9_29_keinSchaltjahr) {
  EXPECT_FALSE(istGueltigesDatum(29, 2, 2025));
}

TEST(istGueltigesDatumTest, uAeK10_29_Jahr100) {
  EXPECT_FALSE(istGueltigesDatum(29, 2, 2100));
}



