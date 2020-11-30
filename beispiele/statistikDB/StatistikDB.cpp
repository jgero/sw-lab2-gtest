#include "StatistikDB.h"
#include <iostream>
namespace {
  const std::string tabellenname = "statistikeintrag";

  std::string holeSpaltenliste(sqlite3 *db) {
    sqlite3_stmt *st; 
    std::string sql_stmt = "select * from " + tabellenname 
      + " where Id= 1;";
    const int erg = sqlite3_prepare(db, sql_stmt.c_str(), 
                                    sql_stmt.length(), &st, 0);
    if(erg != SQLITE_OK) {
      const std::string msg(sqlite3_errmsg(db));
      throw SQLError(msg);
    }
    const int cols = sqlite3_column_count(st);
    std::string spaltenliste;
    for (int i = 1; i < cols; ++i) {
      spaltenliste += sqlite3_column_name(st, i);
      if(i < cols-1) {
        spaltenliste += ",";
      }
    }
    return spaltenliste;
  }
}

void StatistikDB::schreibeTupel(const std::vector<std::string>& vec) {
  static const std::string spaltenliste = holeSpaltenliste(db);
  std::string sqlAnweisung = "insert into " + tabellenname + "("
    +   spaltenliste + ") values(";
  bool erster = true;
  for(const auto& val : vec) {
    if(erster) {
      sqlAnweisung += '\'' + val + '\'';
      erster = false;
    }
    else {
      sqlAnweisung += ",'" + val + '\'';
    }
  }
  sqlAnweisung += ");";
  char *fehlermeldung = nullptr;
  int erg = sqlite3_exec(db, sqlAnweisung.c_str(), 0, 0, 
                         &fehlermeldung);
  if (erg != SQLITE_OK) {                  // Fehler?
    const std::string msg(fehlermeldung);
    sqlite3_free(fehlermeldung); // Freigaben nicht vergessen!
    throw SQLError(msg);
  }
}

std::vector<std::string> StatistikDB::liesTupel(std::size_t nr) const {
  std::string sqlAnweisung = "select * from " + tabellenname 
    + " where Id=" + std::to_string(nr) + ";";
  // 4 Variable zur Speicherung des Ergebnisses aus sqlite3_get_table()
  char *fehlermeldung = nullptr;
  int zeilen;  // muss int sein wegen sqlite3_get_table
  int spalten; // dito
  char **cstringarray = nullptr;
  const int erg = sqlite3_get_table(db, sqlAnweisung.c_str(),
                                    &cstringarray, // Tabelle
                                    &zeilen, &spalten, &fehlermeldung);
  std::vector<std::string> ergebnis;
  if (erg != SQLITE_OK) {                  // Fehler?
    const std::string msg(fehlermeldung);
    sqlite3_free(fehlermeldung); // Freigaben nicht vergessen!
    sqlite3_free_table(cstringarray);
    throw SQLError(msg);
  } else {
    if (zeilen > 0) { 
      for (int s = 1; s < spalten; ++s) {  // Spalte 1 ist Id
        constexpr int z = 1;  // Zeile 0 ist Überschrift
        // Es wird nur eine Zeile abgefragt.
        const char *str = cstringarray[z*spalten + s];
        // NULL-Einträge berücksichtigen
        ergebnis.push_back(str ? str : "");
      }
    }
    sqlite3_free_table(cstringarray); // Freigabe nicht vergessen!
  }
  return ergebnis;
}

void StatistikDB::fuellen(std::ifstream& datei) {
  ueberspringeKopfteil(datei);
  while(true)  {
    const std::vector<std::string> ergebnis = liesTestfall(datei);
    if(ergebnis.size() > 0) {
      schreibeTupel(ergebnis);
    }
    else {
      break;
    }
  }
}

void StatistikDB::leeren() {
  char *fehlermeldung = nullptr;
  const std::string sql_stmt 
    =  "delete from " + tabellenname  + ";";
  const int erg = sqlite3_exec(db, sql_stmt.c_str(), 
                               0,0, &fehlermeldung);
  if (erg != SQLITE_OK) {                  // Fehler?
    std::string msg(fehlermeldung);
    sqlite3_free(fehlermeldung); // Freigaben nicht vergessen!
    throw SQLError(msg);
  }
}
