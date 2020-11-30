#include <gtest/gtest.h>
#include <limits>
#include <iostream>
#include "istBestanden.h"

namespace {
  void checkException(int punkte) {
    try {
      istBestanden(punkte);
    } catch(const std::exception& e) {
      std::cout << "Exception: " << e.what() << '\n';
    }
  }
}

TEST(istBestandenTest, 1_zu_kleine_Punktzahl) {
   ASSERT_THROW(istBestanden(-2), std::invalid_argument);
}

TEST(istBestandenTest, 2_zu_hohe_Punktzahl) {
   ASSERT_THROW(istBestanden(111), std::invalid_argument);
}

TEST(istBestandenTest, 3_kleine_Punktzahl) {
  EXPECT_FALSE(istBestanden(44));
}

TEST(istBestandenTest, 4_ausreichende_Punktzahl) {
  EXPECT_TRUE(istBestanden(88));
}

TEST(istBestandenTest, 5_MAX_INT_Punktzahl) {
  static_assert(sizeof(long) > sizeof(int), "long hat zu wenige Bits!");
  long punkte = 55L + std::numeric_limits<int>::max(); 
  std::cout << "aufgerufen mit " << punkte << " Punkten\n";
  ASSERT_THROW(istBestanden(punkte), std::invalid_argument);
}
TEST(istBestandenTest, 5A_MAX_INT_Punktzahl) {
  static_assert(sizeof(long) > sizeof(int), "long hat zu wenige Bits!");
  long punkte = 55L + std::numeric_limits<int>::max(); 
  std::cout << "aufgerufen mit " << punkte << " Punkten\n";
  checkException(punkte);
  ASSERT_THROW(istBestanden(punkte), std::invalid_argument);
}

TEST(istBestandenTest, 6_MAX_INT_Punktzahl) {
  static_assert(sizeof(long) > sizeof(int), "long hat zu wenige Bits!");
  long punkte =   2L * std::numeric_limits<int>::max() + 70;
  std::cout << "aufgerufen mit " << punkte << " Punkten\n";
  std::cout << "sizeof long =" << sizeof(long) << '\n' << static_cast<int>(punkte) << '\n';
  ASSERT_THROW(istBestanden(punkte), std::invalid_argument);
}

TEST(istBestandenTest, 7_MIN_INT_Punktzahl) {
  static_assert(sizeof(long) > sizeof(int), "long hat zu wenige Bits!");
  long punkte = -55L + std::numeric_limits<int>::min(); 
  std::cout << "aufgerufen mit " << punkte << " Punkten\n";
  ASSERT_THROW(istBestanden(punkte), std::invalid_argument);
}

TEST(istBestandenTest, 8_MIN_INT_Punktzahl) {
  static_assert(sizeof(long) > sizeof(int), "long hat zu wenige Bits!");
  long punkte =   2L * std::numeric_limits<int>::min() + 70;
  std::cout << "aufgerufen mit " << punkte << " Punkten\n";
  ASSERT_THROW(istBestanden(punkte), std::invalid_argument);
}

