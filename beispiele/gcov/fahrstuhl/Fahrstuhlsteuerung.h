#ifndef FAHRSTUHLSTEUERUNG_H
#define	FAHRSTUHLSTEUERUNG_H

enum class Zustand { ZWG, ZWO, ZF, ZX}; // ZX = Fehlerzustand

class Fahrstuhlsteuerung {
public:
  void reset();
  
  /* Rückgabe
   * '0' NOP  keine Aktion
   * '1' TO   Tür öffnen und Timer starten
   * '2' TS   Tür schließen und Timer löschen
   * '3' MS   Motor an
   * '4' MA   Motor aus und Tür öffnen, Timer starten
   * '5' TSMS Tür schließen, Timer löschen und Motor an
   * 'X' Fehler: Der Input darf in diesem Zustand nicht sein
   * 'Y' Fehler: unbekanntes Input-Symbol
   * 'Z' Fehler: undefinierter Zustand
   */
  char uebergang(char input);
private:
  Zustand zustand = Zustand::ZWG;
};

#endif	

