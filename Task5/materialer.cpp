/*
 * materialer.cpp   E.L.
 *
 */
#include "materialer.h"

Materiale::Materiale(const string &startNavn, double startPris) {
  navn = startNavn;
  pris = startPris;
}

void Materiale::skrivUt() const {
  cout << endl
       << "Navn:          " << navn << endl
       << "Pris pr enhet  " << pris <<endl
       << "Enhet: " << passendeEnhet()<< endl;;
}

//////////////////////////////////////////////////////////////////////

Belegg::Belegg(const string &startNavn, double startPris, double startBredde)
      : Materiale(startNavn, startPris),
        breddePaaBelegg(startBredde)
{}

void Belegg::skrivUt() const {
  Materiale::skrivUt();
  cout << "For belegg: " << endl
       << "Bredde:         : " << breddePaaBelegg << endl;
}

//////////////////////////////////////////////////////////////////////

Tapet::Tapet(const string &startNavn, double startPris,
             double startLengdePrRull, double startBreddePrRull)
      : Materiale(startNavn, startPris),
        lengde(startLengdePrRull), bredde(startBreddePrRull)
{}

void Tapet::skrivUt() const {
  Materiale::skrivUt();
  cout << "For tapet: " << endl
       << "Bredde av rull   : " << bredde << endl
       << "Lengde av rull   : " << lengde << endl;
}

//////////////////////////////////////////////////////////////////////

Maling::Maling(const string &startNavn, double startPris,
             double startAntStroek, double startAntKvmPrL)
      : Materiale(startNavn, startPris),
        antStroek(startAntStroek), antKvmPrL(startAntKvmPrL)
{}

void Maling::skrivUt() const {
  Materiale::skrivUt();
  cout << "For maling: " << endl
       << "Antall strøk      : " << antStroek << endl
       << "Ant kvm./l        : " << antKvmPrL << endl;
}
