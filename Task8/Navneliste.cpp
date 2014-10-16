//
// Navneliste.cpp E.L. (forenklet)
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Navneliste {
  public:
    Navneliste(const string &ident, int maks);
    Navneliste(const Navneliste &original);
    Navneliste(Navneliste &&original);
    Navneliste& operator=(const Navneliste &original);
    Navneliste& operator=(const Navneliste &&original);
    const string &finnIdent() const { return ident; }
    bool leggInnNyttNavn(const string &nyttNavn);
    ~Navneliste();  // destruktør, se nedenfor
    friend ostream &operator<<(ostream &ut, const Navneliste &liste);
  
  private:
    string ident;
    int maksAntall; // maks.plass i tabellen
    int antall;  // antall plasser fylt med data
    string *navnene;
}; // Navneliste

ostream &operator<<(ostream &ut, const Navneliste &liste) {
  ut << "Antall navn: " << liste.antall << ", ident: " << liste.ident << endl;
  for (int i = 0; i < liste.antall; i++) {
    ut << liste.navnene[i] << endl;
  }
  return ut;
}

Navneliste fyllListe(Navneliste liste) {  // enkel hjelpefunksjon
  // legger inn maks tre navn
  if (liste.leggInnNyttNavn("Ole")) {
    if (liste.leggInnNyttNavn("Jens")) {
      if (liste.leggInnNyttNavn("Kari")) {
      }
    }
  }
  return liste;
}

/*int main() {
  Navneliste liste1 = fyllListe(Navneliste("Liste1", 5));
  //cout << "Liste 1: " << liste1 << endl;

  //For utprøving av vektorer 
  vector<Navneliste> lister;
  lister.push_back(Navneliste("A", 3));
  cout << "Kapasitet: " << lister.capacity() << endl;
  lister.push_back(Navneliste("B", 3));
  cout << "Kapasitet: " << lister.capacity() << endl;
  lister.push_back(Navneliste("C", 3));
  cout << "Kapasitet: " << lister.capacity() << endl;
  lister.push_back(Navneliste("D", 3));
  cout << "Kapasitet: " << lister.capacity() << endl;
  lister.push_back(Navneliste("E", 3));
  cout << "Kapasitet: " << lister.capacity() << endl;
  
  Navneliste liste2 = liste1;
  cout << "Liste 2: " << liste2 << endl;
  Navneliste *navnepeker = new Navneliste(fyllListe(Navneliste("Liste3", 5)));
  liste2 = *navnepeker;
  cout << "Liste 2: " << liste2 << endl;
  liste2 = move(liste1);
  cout << "Liste 2: " << liste2 << endl;
  

  

  return 0;
}*/

/////////////// Implementasjon av klassen //////////////////////

Navneliste::Navneliste(const Navneliste &original) 
          : ident(original.ident), antall(original.antall), maksAntall(original.maksAntall), 
            navnene(new string[maksAntall]) {
  for (int i = 0; i < antall; i++) {  // dyp kopiering
    navnene[i] = original.navnene[i];
  }
  cout << "Kopikonstruktør brukt, ident " << ident << endl;
} // kopikonstruktør

Navneliste::Navneliste(Navneliste &&original) 
          : ident(original.ident), antall(original.antall), maksAntall(original.maksAntall), 
            navnene(original.navnene) {
  original.navnene = nullptr;
  original.maksAntall = 0;
  cout << "Movekonstruktør brukt, ident " << ident << endl;
} // move-konstruktør

Navneliste::Navneliste(const string &ident, int maks) 
          : ident(ident), navnene(new string[maks]), maksAntall(maks), antall(0) {
  cout << "Konstruktør brukt, ident " << ident << endl;
}

bool Navneliste::leggInnNyttNavn(const string &nyttNavn) {
  if (antall < maksAntall) {
    navnene[antall] = nyttNavn; // lager kopi
    antall++;
    return true;
  } else return false;
}

Navneliste::~Navneliste() {
  if (navnene != nullptr) {
    delete [] navnene;
    cout << "Destruktør: Plass frigjort.";
    navnene = nullptr;
  }
  cout << "På vei ut av destruktøren.\n";
}

Navneliste& Navneliste::operator =(const Navneliste& original){
    cout<<"    BRUKER KOPI OPERATOR"<<endl;
    if(this == &original){
        return *this;        
    }
    if(maksAntall != original.maksAntall){
        maksAntall = original.maksAntall;
        navnene->resize(maksAntall);
    }
    ident = original.ident;
    antall = original.antall;
    for (int i = 0; i < antall; i++) {
        navnene[i] = original.navnene[i];
    }
    return *this;
}

Navneliste& Navneliste::operator =(const Navneliste&& original){
    cout<<"    BRUKER MOVE OPERATOR"<<endl;
    if(this != &original){
        delete [] navnene;
        ident = "";
        maksAntall = 0;
        antall = 0;
        navnene = nullptr;
    }
    return *this;
}



/*
Utskrift uten vektorer:
Konstruktør brukt, ident Liste1
Movekonstruktør brukt, ident Liste1
På vei ut av destruktøren.
Liste 1: Antall navn: 3, ident: Liste1
Ole
Jens
Kari

Destruktør: Plass frigjort.På vei ut av destruktøren.
*/

