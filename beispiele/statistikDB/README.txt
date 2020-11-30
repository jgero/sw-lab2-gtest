Wenn Sie eine Integrierte Entwicklungsumgebung (IDE) benutzen,
vergessen Sie nicht, sqlite3 bekannt zu machen, indem Sie bei
Project - Build options Folgendes eintragen:

Linker settings / Link libraries: sqlite3

---------------------------------------------

Datenbank: Studienstatistik.db

Datenbank neu erzeugen:
- Studienstatistik.db loeschen
- Tabellen anlegen mit
  sqlite3 Studienstatistik.db < createStudienstatistikDB.sql
  
Die Tabelle statistikeintrag wird vom Programm dertest geleert und
danach entsprechend den Daten aus der ACTS-Datei Studienstatistik.txt
befüllt.

dertest prüft anschließend, ob die Einträge in der Datenbank vorliegen.


---------------------------------------------

sqlite3 interaktiv nutzen:

sqlite3 Studienstatistik.db
.help Hilfe
.dump Datenbank anzeigen
.exit beenden

(Punkt vor jedem Kommando nicht vergessen.)




