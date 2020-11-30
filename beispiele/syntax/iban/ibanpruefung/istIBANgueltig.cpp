#include <algorithm>
#include <cctype>
#include "istIBANgueltig.h"

/* Statt einer Kommentierung verweisen wir auf das Dokument
 * http://www.six-interbank-clearing.com/dam/downloads/de/\
standardization/iban/calculator/iban_check_digit_algorithm.pdf 
 * Es beschreibt den Algorithmus, der hier in C++ formuliert wird.
 */

bool istIBANgueltig(std::string iban) {
  // Leerzeichen eliminieren
  iban.erase(std::remove(iban.begin(), iban.end(), ' '), iban.end());
  if(iban.length() < 16 || iban.length() > 34) {
    return false;
  }
  std::string iban1 = std::string(iban, 4) + std::string(iban, 0, 4);
  std::string iban2; 
  for(auto c : iban1) {  // kopieren, dabei Buchstaben nach
    // 1.2 des o.a. dokuments  durch Ziffernpaare ersetzen
    if(std::isdigit(c)) {
      iban2 += c;
    }
    else {
      const int wert = c - 'A' + 10;
      iban2 += wert / 10 + '0';
      iban2 += wert % 10 + '0';
    }
  }
  // Berechnung entspr. Kap. 4 des o.a. Dokuments:
  std::string teil;
  unsigned int anzahl = 9u;
  unsigned int position = 0u;
  unsigned int rest = 0u;
  do {
    teil = std::to_string(rest) + iban2.substr(position, anzahl);
    position += anzahl;
    rest = std::stoul(teil) % 97;
    anzahl = (rest < 10) ? 8 : 7;
  } while(teil.length() > 6);
  return rest == 1u;
}
