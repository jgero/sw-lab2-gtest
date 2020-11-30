#include "gtest/gtest.h"
#include "max3.h"
// für lcov-Detailergebnisse jeweils nur einen Testfall betrachten

// TEST(Maximum_dreier_Zahlen, TF1) {
//   EXPECT_EQ(7, max(7, 5, 4));
// }
// TEST(Maximum_dreier_Zahlen, TF2) {
//   EXPECT_EQ(7, max(5, 7, 4));
// }
// TEST(Maximum_dreier_Zahlen, TF3) {
//   EXPECT_EQ(7, max(4, 5, 7));
// }

// TEST(Maximum_dreier_Zahlen, TF4) {
//   EXPECT_EQ(7, max(7, 4, 5));
// }
TEST(Maximum_dreier_Zahlen, TF5) {
  EXPECT_EQ(7, max(7, 7, 7));
}

