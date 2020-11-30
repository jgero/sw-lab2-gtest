#include "gtest/gtest.h"

template<typename T>
bool istAufsteigendSortiert(const std::vector<T>& vec) {
   for(std::size_t j = 1; j < vec.size(); j++) {
      if(vec[j] < vec[j-1]) {  
         return false;
      }
   }
   return true;
}


TEST(istaufsteigendsortiertTest, leerer_vector) {
   std::vector<int> v;
   EXPECT_TRUE(istAufsteigendSortiert(v));
}

TEST(istaufsteigendsortiertTest, einElement) {
   EXPECT_TRUE(istAufsteigendSortiert( std::vector<int> ( { 7 } )));
}

TEST(istaufsteigendsortiertTest, zweiElemente) {
   EXPECT_TRUE(istAufsteigendSortiert(std::vector<int> ( {1, 1 } )));
   EXPECT_TRUE(istAufsteigendSortiert(std::vector<int> ( {1, 2 } )));
   EXPECT_FALSE(istAufsteigendSortiert(std::vector<int> ( {2, 1 } )));
}

TEST(istaufsteigendsortiertTest, dreiElementeAllePermutationen) {
   for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
         for(int k = 0; k < 3; ++k) {
            std::vector<int> v {i, j, k};
            if(k >= j && j >= i) {
               EXPECT_TRUE(istAufsteigendSortiert(v));
            }
            else {
               EXPECT_FALSE(istAufsteigendSortiert(v));
            }
         }
      }
   }
}


