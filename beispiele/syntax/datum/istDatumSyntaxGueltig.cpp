#include <regex>
#include "istDatumSyntaxGueltig.h"

bool istDatumSyntaxGueltig(const std::string& datum) {
  return std::regex_match(datum, std::regex("(\\d\\d?\\.){2}\\d{4}"));
}
