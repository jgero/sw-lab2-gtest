#include <fstream>
#include <iostream>
#include "../../util/split.h" // String mit Trennzeichen in einen Vector 
                              // aufsplitten

int main() {
  std::ifstream testdaten("testdaten.txt");   // Input
  std::ofstream ergebnis("../dertest.cpp");    // Output
  ergebnis << "// Von generator/generator.exe generierte Datei!\n"
    "#include <gtest/gtest.h>\n#include \"monatsbeitrag.h\"\n";
  std::string zeile;
  std::getline(testdaten, zeile);
  auto faktoren = split(zeile, ",");
  std::size_t testfall = 0;

  while(testdaten.good()) {
    std::getline(testdaten, zeile);
    if(zeile.length() > 3) {
      ergebnis << "\nTEST(monatsbeitragTest, TF" << ++testfall 
               << ") {\n  Monatsbeitrag mb;\n"
                  "  std::set<std::string> abt {";
      auto testparameter = split(zeile, ",");
      auto mitgliedsstatus = testparameter.at(testparameter.size()-2);
      auto orakel = testparameter.back();
      bool ersterEintrag = true;
      for(std::size_t i = 0; i < testparameter.size() - 1u; ++i) {
        if(testparameter[i] == "true") {
          if(!ersterEintrag) {
            ergebnis << ", ";
          }
          ersterEintrag = false;
          ergebnis << '"' << faktoren[i] << '"';
        }
      }
      ergebnis << "};\n  EXPECT_EQ(mb.beitrag(\"" 
               << mitgliedsstatus << "\", abt), " 
               << orakel << ");\n}\n";
    }
  }
}
