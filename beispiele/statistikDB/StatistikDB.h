#ifndef STATISTIKDB_H
#define STATISTIKDB_H
#include <cstddef>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sqlite3.h>
#include "dateiIO.h"

struct SQLError : public std::runtime_error {
  SQLError(const std::string &msg)
      : std::runtime_error(std::string("SQL-Fehler: ") + msg) {}
};

class StatistikDB {
public:
  StatistikDB(const char *dateiname) : db(nullptr) {
    if (sqlite3_open(dateiname, &db) != SQLITE_OK) { // Fehler?
      const char *fehlermeldung = sqlite3_errmsg(db);
      sqlite3_close(db);
      throw SQLError(fehlermeldung);
    }
  }

  ~StatistikDB() { sqlite3_close(db); }

  void schreibeTupel(const std::vector<std::string>& vec);

  std::vector<std::string> liesTupel(std::size_t nr) const;

  void fuellen(std::ifstream& datei);

  void leeren();
private:
  sqlite3 *db;
  StatistikDB(const StatistikDB &) = delete; // soll nicht kopiert werden
  StatistikDB &operator=(const StatistikDB &) =
      delete; // soll nicht zugewiesen werden
};

#endif
