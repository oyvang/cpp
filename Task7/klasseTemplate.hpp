/* 
 * File:   klasseTemplate.hpp
 * Author: gm
 *
 * Created on October 14, 2014, 2:01 PM
 */

#ifndef KLASSETEMPLATE_DEFINERT
#define KLASSETEMPLATE_DEFINERT

#include <iostream>
#include <cstdlib> 
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

template <class type1, class type2>
class Par {
      public:
        Par();
        Par(type1 a, type2 b);
        Par(const Par<type1,type2> &original);
        ~Par();
        Par operator+(Par<type1,type2> &denAndre) ;
        bool operator>( Par<type1,type2> &denAndre);
        type1 getFirstElement(){ return firstElement; }
        type2 getSecondElement(){ return secondElement; }
        void setfirstElement(type1 element){firstElement = element;}
        void setSecondElement(type2 element){secondElement = element;}
       private:
           type1 firstElement;
           type2 secondElement;

};



template <class type>
class Tabell {
  public:
  Tabell(int initMaks = 5); // default argumentverdi lik 5
     // burde også laget kopikonstruktør, pga peker som datamedlem
  ~Tabell();

   void settVerdi(const type &nyverdi);
   type finnVerdi(int indeks) const;
   int  finnAntall() const;
   void sorter();
   int soek(type soekEtter);
   Tabell &operator=(const Tabell &denAndre);
   type& operator[] (int index) {
          return dataene[index];
   }

   private:
   type *dataene;    // peker som datamedlem
   int   antall;     // aktuelt antall
   int   maksAntall; // maksimalt antall
};

class Broek {
    public:  
      Broek();
      Broek(int initTeller, int initNevner);             
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
Broek operator-(int tall, const Broek &denAndre);  


template <class type1, class type2>
Par<type1,type2>::Par(){
    firstElement=0;
    secondElement=0;
    }
template <class type1, class type2>
Par<type1,type2>::Par(type1 a, type2 b){
    firstElement=a;
    secondElement=b;
}

template <class type1, class type2>
Par<type1,type2>::Par(const Par<type1,type2>& original):firstElement(original.firstElement),secondElement(original.secondElement){}

template <class type1, class type2>
Par<type1,type2> Par<type1,type2>::operator+(Par<type1,type2> &denAndre){
    Par<type1,type2> sum;
    
    sum.setfirstElement(this->getFirstElement() + denAndre.getFirstElement());
    sum.setSecondElement(this->getSecondElement() + denAndre.getSecondElement());    
    return sum;
}

template <class type1, class type2>
bool Par<type1,type2>::operator >( Par<type1,type2>& denAndre) {
    Par first;
    double large = this->getFirstElement() + this->getSecondElement();
    double small = denAndre.getFirstElement() + denAndre.getSecondElement();
    return large>small;
}

template<class type1, class type2>
Par<type1,type2>::~Par(){
    
}

template <class type>
Tabell<type>::Tabell(int initMaks) {
  dataene = new type[initMaks];
  maksAntall = initMaks;
  antall = 0;
}

template <class type>
Tabell<type>::~Tabell() {
  delete [] dataene;
  dataene = nullptr;
  maksAntall = antall = 0;
}

template <class type>
void Tabell<type>::settVerdi(const type &nyVerdi) {
  if (antall < maksAntall)  {
    dataene[antall] = nyVerdi;    // Plasser nytt element bakerst
    antall++;
  }
  // else utvid tabellen - ikke implementert
}


template <class type>
type Tabell<type>::finnVerdi(int indeks) const {
  if (indeks >= 0 && indeks < antall) return dataene[indeks];
  else {
    cerr << "Ugyldig indeks i tabell-template finnVerdi(): "
         << indeks << endl;
    exit(EXIT_FAILURE);   // fra <cstdlib>
  }
}

template <class type>
int Tabell<type>::finnAntall() const {
  return antall;
}

template <class type>
Tabell<type>& Tabell<type>::operator=(const Tabell &denAndre) {
  delete [] dataene;
  maksAntall = denAndre.maksAntall;
  antall = denAndre.antall;
  dataene = new type[maksAntall];
  for (int i = 0; i < antall; i++) dataene[i] = denAndre.dataene[i];
  for (int j = antall; j < maksAntall; j++) dataene[j] = 0;
  return *this;
}


template <class type>
void Tabell<type>::sorter(){
        for (int i = 0; i < antall; i++) {
        int hittilMinst = i;
        for (int j = i + 1; j < antall; j++) {
            if (dataene[j] < dataene[hittilMinst]) hittilMinst = j;
        }
        type hjelp = dataene[i];
        dataene[i] = dataene[hittilMinst];
        dataene[hittilMinst] = hjelp;
    }
}

template <class type>
int Tabell<type>::soek(type soekEtter){
    int i = 0;
    while (i < antall && dataene[i] != soekEtter) i++;
        if (i < antall) return i;
        else return -1;
}
#endif




