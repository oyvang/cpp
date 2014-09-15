//
// FlateTest.cpp  E.L. 
//
#include <iostream>
#include <string>

using namespace std;

class Flate {
  public:
    Flate(const string &startNavn, double startLengde, double startBredde);
    const string &finnNavn() const;
    double finnLengde() const;
    double finnBredde() const;
    double finnAreal() const;
    double finnOmkrets() const;

  private:
    string navn;  // til identifikasjon
    double lengde;
    double bredde;
};


int main() {
    
    Flate flater[5] = {Flate("nr1", 2, 3), Flate("nr2", 4, 3), Flate("nr3", 5, 3),
    Flate("nr4", 6, 3), Flate("nr5", 7, 3)};
    
    
    Flate *peker = flater;
    for (int i = 0; i < 5; i++) {
        cout<<peker->finnNavn()<<" <A>: "<<peker->finnAreal()<<endl;
        peker++;

    }

    return 0;
}


Flate::Flate(const string &startNavn, double startLengde, double startBredde) {
  navn = startNavn;
  lengde = startLengde;
  bredde = startBredde;
}

const string &Flate::finnNavn() const {
  return navn;
}

double Flate::finnLengde() const {
  return lengde;
}

double Flate::finnBredde() const {
  return bredde;
}

double Flate::finnAreal() const {
  return bredde * lengde;
}

double Flate::finnOmkrets() const {
  return 2 * (lengde + bredde);
}

