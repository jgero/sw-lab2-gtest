#include "gtest/gtest.h"
#include "undoder.h"

TEST(komplexeBedingung, Tab5_7_Test_2) {
  EXPECT_EQ(true, undoder(1, 1, -1));
}
TEST(komplexeBedingung, Tab5_7_Test_3) {
  EXPECT_EQ(true, undoder(1, -1, 1));
}
TEST(komplexeBedingung, Tab5_7_Test_4) {
  EXPECT_EQ(false, undoder(1, -1, -1));
}
TEST(komplexeBedingung, Tab5_7_Test_6) {
  EXPECT_EQ(false, undoder(-1, 1, -1));
}
/*
TEST(komplexeBedingung, Tab5_8_Test_5) {
  EXPECT_EQ(true, undoder(-1, 1, 1));
}
TEST(komplexeBedingung, Tab5_8_Test_7) {
  EXPECT_EQ(true, undoder(-1, -1, 1));
}
*/
