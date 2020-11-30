#ifndef SPLIT_H
#define SPLIT_H
#include <string>
#include <vector>
// String mit Trennzeichen in einen Vector aufsplitten
inline   // spart split.cpp
std::vector<std::string> split(const std::string &s,
                               const std::string &trenn) {
  std::vector<std::string> v;
  std::string::size_type start = 0;
  std::string::size_type pos;
  do {
    pos = s.find_first_of(trenn, start);
    v.push_back(s.substr(start, pos - start));
    start = pos + 1;
  } while (pos != std::string::npos);
  return v;
} 
#endif
