#include <regex>
#include "istIBANsyntaxgueltig.h"

bool istIBANsyntaxGueltig(const std::string& iban) {
  return std::regex_match(iban, std::regex("DE(\\d *){20}"));
}
