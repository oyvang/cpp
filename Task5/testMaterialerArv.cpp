//
// testMaterialeArv.cpp
//
#include "materialer.h"

const int antMaterialer = 3;
int main() {
  Belegg belegget("Super Duper Dux", 433.50, 4);
  Tapet tapeten("Soldogg", 200, 12, 0.6);
  Maling malingen("Extra", 125, 2, 12);

  cout << "Utskrift der objektene bruker sin egen skrivUt()-funksjon:\n";
  belegget.skrivUt();
  tapeten.skrivUt();
  malingen.skrivUt();

  Materiale *materialer[antMaterialer];
  materialer[0] = &belegget;
  materialer[1] = &tapeten;
  materialer[2] = &malingen;

  cout << "\nUtskrift der vi håndterer objektene samlet\n";
  for (int i = 0; i < antMaterialer; i++) {
    materialer[i]->skrivUt();
  }
  return 0;
}

/* Utskrift:
Utskrift der objektene bruker sin egen skrivUt()-funksjon:

Navn:          Super Duper Dux
Pris pr enhet  433.5
For belegg:
Bredde:         : 4

Navn:          Soldogg
Pris pr enhet  200
For tapet:
Bredde av rull   : 0.6
Lengde av rull   : 12

Navn:          Extra
Pris pr enhet  125
For maling:
Antall str°k      : 2
Ant kvm./l        : 12

Utskrift der vi håndterer objektene samlet

Navn:          Super Duper Dux
Pris pr enhet  433.5
For belegg:
Bredde:         : 4

Navn:          Soldogg
Pris pr enhet  200
For tapet:
Bredde av rull   : 0.6
Lengde av rull   : 12

Navn:          Extra
Pris pr enhet  125
For maling:
Antall strøk      : 2
Ant kvm./l        : 12
*/
