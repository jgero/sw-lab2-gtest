#ifndef DATEIIO_H
#define DATEIIO_H
#include <fstream>
#include <string>
#include <vector>

void ueberspringeKopfteil(std::ifstream& datei);
std::vector<std::string> liesTestfall(std::ifstream& datei);

#endif
