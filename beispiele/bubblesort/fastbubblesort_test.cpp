#include <algorithm>          // std::sort()
#include "gtest/gtest.h"
#include "fastbubblesort.t"

namespace {
template<typename T>
void show(const std::vector<T>& vec) {
   std::cout << "vec = ";
   for(auto w : vec) {
      std::cout << w << ' ';
   }
   std::cout << '\n';
}
}


TEST(fastbubblesortTest, vector_leer) {
   std::vector<int> v;
   std::vector<int> ergebnis;
   // undefined behaviour, fastbubblesort1(v) wirft keine Exc.!
   fastbubblesort1(v);
   ASSERT_EQ(ergebnis, v);
}


TEST(fastbubblesortTest, einElement) {
   std::vector<int> v { 1000 };
   std::vector<int> ergebnis { 1000 };
   fastbubblesort1(v);
   ASSERT_EQ(ergebnis, v) << "Vektoren sind ungleich!";
   //ASSERT_EQ(ergebnis, v);
}


TEST(fastbubblesortTest, zweiElementeAllePermutationen) {
   for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
         std::vector<int> v {i, j};
         std::vector<int> ergebnis = v; 
         std::sort(ergebnis.begin(), ergebnis.end());
         fastbubblesort1(v);
         ASSERT_EQ(ergebnis, v);
      }
   }
}


TEST(fastbubblesortTest, dreiElementeAllePermutationen) {
   for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
         for(int k = 0; k < 3; ++k) {
               std::vector<int> v {i, j, k};
               show(v);
               std::vector<int> ergebnis = v;
               std::sort(ergebnis.begin(), ergebnis.end());
               fastbubblesort1(v);
               EXPECT_EQ(ergebnis, v);
         }
      }
   }
}
