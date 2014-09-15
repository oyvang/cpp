//
// Navneliste6.cpp
//
// smart pointer i stedet for vanlig peker
//
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Navneliste {
  public:
    Navneliste(int maks);
    Navneliste(Navneliste& origianl);
    bool leggInnNyttNavn(const string &nyttNavn);
    bool settNavn(const string &navn, int indeks);
    bool finnNavn(const string &navn) const;  // false hvis navn ikke finnes
    int finnAntallNavn() const;
    bool finnNavn(int indeks, string &navn) const; // false hvis ugyldig indeks
    //~Navneliste();  // trenger ikke tenke på denne

  private:
    int maksAntall; // maks.plass i tabellen
    int antall;  // antall plasser fylt med data
    unique_ptr<string []> navnene; // i stedet for string *navnene;
}; // Navneliste

//////////////////////////////////////////////////////
void skrivListe(const Navneliste &liste) {  // hjelpefunksjon
  for (int i = 0; i < liste.finnAntallNavn(); i++) {
    string navn;
  liste.finnNavn(i, navn);
    cout << navn << endl;
  }
}

int main() {
  Navneliste liste1(5);
  liste1.leggInnNyttNavn("Ole");
  liste1.leggInnNyttNavn("Jens");
  liste1.leggInnNyttNavn("Petter");
  liste1.leggInnNyttNavn("Kari");
  
  //TESTRT AV KOPIKUNSTRUKTØR
  Navneliste kopiListe1(liste1);


  skrivListe(liste1);

  return 0;
}

Navneliste::Navneliste(int maks) : maksAntall(maks), antall(0), navnene(new string[maks]) {
}
//OPPGAVEN! SE TESTING AV DENNE I MAIN
Navneliste::Navneliste(Navneliste& original) : maksAntall(original.maksAntall), antall(original.antall), navnene(new string[original.maksAntall]){
    for (int i = 0; i < original.maksAntall; i++) {
        navnene[i] = original.navnene[i];
    }
}

bool Navneliste::settNavn(const string &navn, int indeks) {
  if (indeks >= 0 && indeks < antall) {
    navnene[indeks] = navn;
    return true;
  } return false;
}

bool Navneliste::leggInnNyttNavn(const string &nyttNavn) {
  if (antall < maksAntall) {
    navnene[antall] = nyttNavn; // lager kopi
    antall++;
    return true;
  } else return false;
}


bool Navneliste::finnNavn(const string &navn) const {
  for (int i = 0; i < antall; i++) {
    if (navnene[i] == navn) return true;  // RETUR, navn funnet
  }
  return false; // RETUR, navnet ikke funnet
}

int Navneliste::finnAntallNavn() const {
  return antall;
}

bool Navneliste::finnNavn(int indeks, string &navnet) const {
  if (indeks >= 0 && indeks < antall) {
    navnet = navnene[indeks];
  return true;
  }
  return false;
}

/*
Ole
Jens
Petter
Kari
*/

