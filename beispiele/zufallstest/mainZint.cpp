#include "zufallstest.h"

int main() {
  Zufallstest testobjekt(3, 1000);    // Länge der Folge, Zahl der Versuche
  testobjekt.execute();
}
