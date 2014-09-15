/*
 * materialer.h   E.L.
 *
 */
#ifndef MATERIALE_DEFINERT
  #define MATERIALE_DEFINERT

  #include <string>
  #include <iostream>
  using namespace std;

  class Materiale {

    public:
      Materiale(const string &startNavn, double startPris);
      const string &finnNavn() const { return navn; }
      double finnPrisPrEnhet() const { return pris; }
      virtual string passendeEnhet() const { return enhet; }
      virtual void  skrivUt() const;

    private:
      string navn;  // identifiserer materialet
      double pris;  // pris pr enhet
      const string enhet = "Materiale";
  };

  class Belegg: public Materiale {
    public:
      Belegg(const string &startNavn, double startPris, double startBredde);
      double finnBredde() const { return breddePaaBelegg; }
      virtual string passendeEnhet() const { return enhet; }
      virtual void skrivUt() const;

    private:
      const string enhet = "meter";
      double breddePaaBelegg;    // meter
  };

  class Tapet: public Materiale {
    public:
      Tapet(const string &startNavn, double startPris,
            double startLengdePrRull, double startBreddePrRull);
      double finnLengdePrRull() const { return lengde; }
      double finnBreddePrRull() const { return bredde; }
      virtual string passendeEnhet() const { return enhet; }
      virtual void skrivUt() const;

    private:
      const string enhet = "rull";
      double lengde;    // meter
      double bredde;     // meter
  };

  class Maling: public Materiale {
    public:
      Maling(const string &startNavn, double startPris,
            double startAntStroek, double startAntKvmPrL);
      double finnAntStroek() const { return antStroek; }
      double finnAntKvmPrL() const { return antKvmPrL; }
      virtual string passendeEnhet() const { return enhet; }
      virtual void skrivUt() const;

    private:
      const string enhet = "liter";
      double antStroek;
      double antKvmPrL;
  };

#endif