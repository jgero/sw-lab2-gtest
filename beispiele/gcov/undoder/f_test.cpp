#include "gtest/gtest.h"
#include "f.h"

TEST(komplexeBedingung_f1, Tab5_5_Test_2) {
  EXPECT_EQ(true, f1(1, 1, -1));
}
TEST(komplexeBedingung_f1, Tab5_5_Test_3) {
  EXPECT_EQ(true, f1(1, -1, 1));
}
TEST(komplexeBedingung_f1, Tab5_5_Test_4) {
  EXPECT_EQ(false, f1(1, -1, -1));
}
TEST(komplexeBedingung_f1, Tab5_5_Test_6) {
  EXPECT_EQ(false, f1(-1, 1, -1));
}

// Dasselbe mit f2()
TEST(komplexeBedingung_f2, Tab5_5_Test_2) {
  EXPECT_EQ(true, f2(1, 1, -1));
}
TEST(komplexeBedingung_f2, Tab5_5_Test_3) {
  EXPECT_EQ(true, f2(1, -1, 1));
}
TEST(komplexeBedingung_f2, Tab5_5_Test_4) {
  EXPECT_EQ(false, f2(1, -1, -1));
}
TEST(komplexeBedingung_f2, Tab5_5_Test_6) {
  EXPECT_EQ(false, f2(-1, 1, -1));
}


