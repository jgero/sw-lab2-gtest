#include <gtest/gtest.h>
#include "rabatt.h"
// Beträge sind in Cent!

// gültige Äquivalenzklassen
TEST(RabattTest, gAeK31_Morgens_0_B_150) {
   EXPECT_EQ(rabatt(10000, 9, 0), 500);
}

TEST(RabattTest, gAeK32_Morgens_150_B_200) {
   EXPECT_EQ(rabatt(17000, 9, 30), 1000);
}

TEST(RabattTest, gAeK33_Morgens_200_B_10000) {
   EXPECT_EQ(rabatt(35000, 8, 27), 1750);
}

TEST(RabattTest, gAeK34_Tag_0_B_150) {
   EXPECT_EQ(rabatt(8000, 17, 5), 0);
}

TEST(RabattTest, gAeK35_Tag_150_B_10000) {
   EXPECT_EQ(rabatt(16000, 16, 5), 1000);
}

// ungültige Äquivalenzklassen
TEST(RabattTest, uAeK11_zuhoherBetrag) {
   ASSERT_THROW(rabatt(1000001, 12, 0), std::invalid_argument);
}

TEST(RabattTest, uAeK12_Betrag_0) {
   ASSERT_THROW(rabatt(0, 12, 0), std::invalid_argument);
}

TEST(RabattTest, uAeK21_UhrzeitZuspaet) {
   ASSERT_THROW(rabatt(50000, 20, 1), std::invalid_argument);
}

TEST(RabattTest, uAeK22_UhrzeitZufrueh) {
   ASSERT_THROW(rabatt(50000, 7, 30), std::invalid_argument);
}

TEST(RabattTest, uAeK23_UhrzeitZugross) {
   ASSERT_THROW(rabatt(50000, 24, 0), std::invalid_argument);
}
