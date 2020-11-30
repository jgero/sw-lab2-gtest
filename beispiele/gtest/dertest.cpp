#include <gtest/gtest.h>
#include "pruefling.h"

TEST(Pruefling_Test, 1_null) {
  pruefling p(0.0);
  EXPECT_DOUBLE_EQ(.0, p.attributquadrat());
}
TEST(Pruefling_Test, 2_eins) {
  pruefling p(1.0);
  EXPECT_DOUBLE_EQ(1.0, p.attributquadrat());
}
TEST(Pruefling_Test, 3a_positiveZahl) {
  pruefling p(2.5);
  EXPECT_DOUBLE_EQ(6.25, p.attributquadrat());
}
TEST(Pruefling_Test, 3b_positiveZahl) {
  pruefling p(10.0);
  EXPECT_DOUBLE_EQ(1000.0, p.attributquadrat());
}

TEST(Pruefling_Test, 4_ULP_test) {
  pruefling p(2.5);
  EXPECT_DOUBLE_EQ(6.25 + 1e-15, p.attributquadrat());
  if(6.25 + 1e-15 != 6.25) {
    std::cout << "UNGLEICH!\n";
  }
}

// .. usw.
