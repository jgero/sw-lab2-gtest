#include "Fahrstuhlsteuerung.h"

void Fahrstuhlsteuerung::reset() {
  zustand = Zustand::ZWG;
}

char Fahrstuhlsteuerung::uebergang(char input) {
  char aktion = '0';
  switch (zustand) {
    case Zustand::ZWG:
      switch (input) {
        case 's':
          aktion = '1';
          zustand = Zustand::ZWO;
          break;
        case 'b':
          aktion = '3';
          zustand = Zustand::ZF;
          break;
        case 'e':
        case 't':
          aktion = 'X';
          zustand = Zustand::ZX;
          break;
        default:
          aktion = 'Y';
          zustand = Zustand::ZX;
      }
      break;
    case Zustand::ZWO:
      switch (input) {
        case 's':
          aktion = '0';
          break;
        case 'b':
          aktion = '5';
          zustand = Zustand::ZF;
          break;
        case 'e':
          aktion = 'X';
          zustand = Zustand::ZX;
          break;
        case 't':
          aktion = '2';
          zustand = Zustand::ZWG;
          break;
        default:
          aktion = 'Y';
          zustand = Zustand::ZX;
      }
      break;
    case Zustand::ZF:
      switch (input) {
        case 's':
        case 'b':
        case 't':
          aktion = '0';
          break;
        case 'e':
          aktion = '4';
          zustand = Zustand::ZWO;
          break;
         default:
           aktion = 'Y';
           zustand = Zustand::ZX;
      }
      break;
     case Zustand::ZX :
       aktion = 'Z';
       zustand = Zustand::ZX;
       break;
     default: ;
  }
  return aktion;
}

