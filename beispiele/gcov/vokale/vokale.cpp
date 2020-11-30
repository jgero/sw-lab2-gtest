#include "vokale.h"
#include <cstring>

// Vokale zählen (ohne Umlaute)
std::size_t vokale(const std::string& str) {
  std::size_t z = 0;
  for(auto c : str) {
    if(isupper(c)) {
      c = std::tolower(c);   // Umwandlung in Kleinbuchstaben
    }
    if(   c == 'a' 
       || c == 'e'
       || c == 'i'
       || c == 'o'
       || c == 'u') {
      ++z;
    }
  }
  return z;
}

