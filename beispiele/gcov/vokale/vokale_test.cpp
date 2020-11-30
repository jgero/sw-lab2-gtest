#include "gtest/gtest.h"
#include "vokale.h"

// TEST(Vokale_zaehlen, Boundary_Interior_Test_0) {
//   EXPECT_EQ(0, vokale(""));
// }

// TEST(Vokale_zaehlen, Boundary_Interior_Test_1) {
//   EXPECT_EQ(1, vokale("A"));
// }

TEST(Vokale_zaehlen, Boundary_Interior_Test_2) {
  EXPECT_EQ(1, vokale("AX"));
}

