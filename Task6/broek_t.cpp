//-------------------------------------------------------------------
//
// broek_t.cpp 
//
// Program som tester noen av funksjonene i klassen brøk.
//
#include <iostream>
#include <string>
#include "broek.h"

using namespace std;

void skriv(const string &tekst, const Broek &Broek);

int main() {
  Broek a(10, 20);
  Broek b(3, 4);
 
  /*
   * OPPGAVE 1a se broek.h og broek.cpp
   */
  Broek e = a - 5;
  Broek f = 5 - a;
  Broek g = 5 - 3 - a - 7 - b;
  
  /**
   * OPPGAVE 1b
   * Den bruker disse operatorene i denne rekkefølgen
   * (int tall, const Broek &denAndre)
   *(const Broek &denAndre)
   *(int heltall)
   *(const Broek &denAndre)
   *(const Broek &denAndre)
   */
  
  skriv("\t\t broekA - 5  =  ", e);
  skriv("\t\t 5 - broakA  =   ", f);
  skriv("5 - 3 - broekA - 7 - broekB  = ", g);
  

 

  return 0;
} 

//-------------------------------------------------------------------
//
// Funksjon for å skrive en brøk.
//
void skriv(const string &tekst, const Broek  &broek) {
  cout << tekst << broek.finnTeller() << " / ";
  cout << broek.finnNevner() << endl;
} 

