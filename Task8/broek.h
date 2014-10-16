//-------------------------------------------------------------------
//
// broek.h  
//
// Klasse for å behandle brøker.
// NB: Hvis en brøk får nevner 0 avluttes hele programmet!
//
#include <string>
#include <vector>

using namespace std;

#ifndef BROEK_DEFINERT
  #define BROEK_DEFINERT

  class Broek {
    public:  
      Broek();
      //~Broek();
      Broek(int initTeller, int initNevner);  
      //Broek(const Broek& original);
      //Broek(Broek &&original);
      //Broek& operator=(const Broek &&original);
      void settBroek(int nyTeller, int nyNevner = 1);               
      int finnTeller() const { return teller; }
      int finnNevner() const { return nevner; }                   
      Broek operator+(const Broek &denAndre) const;    
      Broek operator-(const Broek &denAndre) const;
      Broek operator-(const int heltall) const;
      Broek operator*(const Broek &denAndre) const;    
      Broek operator/(const Broek &denAndre) const;    
      Broek operator-() const;
      Broek &operator++();  // Preinkrement
      Broek &operator--();  // Predekrement 
      Broek &operator+=(const Broek &denAndre);          
      Broek &operator-=(const Broek &denAndre);          
      Broek &operator*=(const Broek &denAndre);          
      Broek &operator/=(const Broek &denAndre);          
      Broek &operator=(const Broek &original);          
      bool operator==(const Broek &denAndre) const;    
      bool operator!=(const Broek &denAndre) const;    
      bool operator<=(const Broek &denAndre) const;    
      bool operator>=(const Broek &denAndre) const;    
      bool operator<(const Broek &denAndre) const;    
      bool operator>(const Broek &denAndre) const;    

    private:
      void forkort();
      int sammenlikn(const Broek &denAndre) const;    
      int teller;
      int nevner;
    }; 
    Broek operator-(int tall, const Broek &denAndre);  //Denne har jeg lagt til
    
#endif