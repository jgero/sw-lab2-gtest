#include <iostream>
#include <limits>
#include <iomanip>

template<typename T>
void binaereAusgabe(unsigned int offset, T zahl) {
  for(unsigned int i = 0; i < offset; ++i) {
    std::cout << ' ';
  }
  int anzahlDerBytes = sizeof zahl;
  int anzahlDerBits = 8 * anzahlDerBytes;
  for (int k = anzahlDerBits - 1; k >= 0; --k) {
    if (zahl & (1LL << k)) {
      std::cout << '1';
    } else {
      std::cout << '0';
    }
  }
}

int main() {
  std::cout << "Informationsverlust bei der Typumwandlung\n";
  long long zahl = 2LL* std::numeric_limits<int>::max() +70;
  binaereAusgabe(0,zahl);
  std::cout << "  long long binär. Als Dezimalzahl: " << zahl  << '\n';
  int arg = static_cast<int>(zahl);
  binaereAusgabe(32,arg);
  std::cout << "  int binär. Als Dezimalzahl: " << arg  << '\n';
  std::cout << '\n';
  std::cout << "  long long hexadezimal: " << std::setbase(16);
  std::cout.width(9);
  std::cout.fill('x');
  std::cout    << zahl  << '\n';
  std::cout << "  int hexadezimal      : " << std::setbase(16);
  std::cout.width(9);
  std::cout.fill('0');
  std::cout << arg  << '\n';
  std::cout.width(9);
  std::cout.fill('0');
  std::cout << std::numeric_limits<int>::max()  << '\n';
}
