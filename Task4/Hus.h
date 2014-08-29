//
// Hus.h  E.L.
//
// Deklarerer klassene Hus, Person og Bud
//
  #ifndef HUS_DEFINERT
  #define HUS_DEFINERT
  #include <string>
  #include <iostream>

  using namespace std;

  class Person {
    public:
      Person() {}  // trengs pga at Bud har standardkonstruktør
      Person(const string &startNavn, const string &startAdresse, const string &startTelefon);  // Husk å bruke kopikonstruktøren ved initiering av datamedlemmene

      const string &finnNavn() const { return navn; }
      const string &finnAdresse() const { return adresse; }
      const string &finnTelefon() const { return telefon; }

    private:
      string navn;
      string adresse;
      string telefon;
  };

  class Bud {
    public:
      Bud() {} // trengs når tabellen skal lages
      Bud(long startPris, const Person &startBudgiver);

      long finnPris() const { return pris; }
      const Person &finnBudgiver() const { return budgiver; }
      void settPris(long nyPris) { pris = nyPris; }
      void settBudgiver(const Person &nyBudgiver) { budgiver = nyBudgiver; }

    private:
      long pris;
      Person budgiver;
  };

  class Hus {
    public:
      Hus(int startMaksAntBud, const string &startAdresse, const Person &startEier);
      Hus(const Hus &original);
      ~Hus();

      int finnHusnr() const { return husnr; }
      const Person &finnEier() const { return eier; }
      const string &finnAdresse() const { return adresse; }
      int finnAntallBud() const { return antallBud; }

      void leggInnNyttBud(
             long  pris,              // Inn
             const Person &person);   // Inn
      bool finnBudNr(  // returnerer false hvis ugyldig indeks
             int     indeks,          // Inn
             long   &pris,            // Ut
             Person &budgiver) const; // Ut
      bool finnHoyesteBud(  // returnerer false hvis ingen bud
             long   &pris,            // Ut
             Person &budgiver) const; // Ut, ikke verdi hvis ingen bud

      static int finnHusnrMaks() {return husnrMaks; }

    private:
      static int husnrMaks ;  // felles for alle hus-objekter

      int husnr;
      string adresse;
      Person eier;
      int antallBud;
      int maksAntBud;
      Bud *budene;  // denne pekeren skal peke til en tabell i det frie lageret. Tabellen skal utvides hvis den blir full (se oppgave med løsning i leksjonen).
  };
#endif