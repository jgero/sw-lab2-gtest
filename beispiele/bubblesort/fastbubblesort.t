#include <cstddef>
#include <vector>

template<typename T>
void fastbubblesort(std::vector<T>& vec) {
   if(vec.size() == 0)
      return;
   T temp;
   do {
      temp = vec[0];
      for(std::size_t j = 1; j < vec.size(); j++) {
         if(vec[j] < vec[j-1]) {          // vertauschen
            temp     = vec[j-1];
            vec[j-1] = vec[j];
            vec[j]   = temp;
         }
      }
   } while(temp != vec[0]);                // {\tt false} = keine Vertauschung mehr
}

template<typename T>
void fastbubblesort1(std::vector<T>& vec) {
   bool vertauscht;
   do {
      vertauscht = false;
      for(std::size_t j = 1; j < vec.size(); j++) {
         if(vec[j] < vec[j-1]) {          // vertauschen
            int temp     = vec[j-1];
            vec[j-1] = vec[j];
            vec[j]   = temp;
            vertauscht = true;
         }
      }
   } while(vertauscht);                // {\tt false} = keine Vertauschung mehr
}
