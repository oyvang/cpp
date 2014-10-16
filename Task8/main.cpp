/* 
 * File:   main.cpp
 * Author: gm
 *
 * Created on October 14, 2014, 2:36 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "broek.h"

using namespace std;

void listTabell(vector<double> tabell){
    cout<<"  ";
    for (int i = 0; i < tabell.size(); i++) {
        cout<< tabell[i]<<" - ";
    }
    cout<<endl;
}


int main() {
    
    vector<double> tabell;

    tabell.push_back(1.1);
    tabell.push_back(1.2);
    tabell.push_back(1.3);
    tabell.push_back(1.4);
    tabell.push_back(1.5);
    cout<<"Original tabell"<<endl;
    listTabell(tabell);
    
    cout<<"Bruker front() og får verdi: "<<tabell.front()<<" skal være 1.1"<<endl;

    cout<<"Bruker back() og får verdi: "<< tabell.back()<<" skal være 1.5"<<endl;
    
    tabell.insert(tabell.begin()+1, 2.1);
    cout<<"Tabell etter insert()"<<endl;
    listTabell(tabell);
    
    cout<<"Prøver å bruke find() til å søke etter 1.4 og får verdi: ";
    vector<double>::iterator it;
    it = find(tabell.begin(),tabell.end(), 1.4);
    cout<< *it << " skal finne 1.4"<<endl;
    
    cout<<"Prøver å bruke find() til å søke etter 1.9 og får verdi: ";
    it = find(tabell.begin(),tabell.end(), 1.9);
    cout<< *it <<" skal ikke finne og dermed få 0"<<endl;
    
    //Oppgave 2
    //Om man skal frigjøre pekerplassen etter kopiering så er det best
    //å bruke en move-konstruktør som sletter objektet for oss men tar vare på
    //pekeren plassen. i Broek har vi ingen pekere så tror ikke vi trenger dette her.
    //Hadde vi brukt en klasse som inneholder en liste med brøker så ville jeg nok
    //ha implementert movekonstruktør og tilordningsoperatorer
    
    //vector.erase() bruker destruktør 1 gang
    cout<<"\nOPPGAVE 2a"<<endl;

  Broek *en = new Broek(3,6);
  Broek *to = new Broek(4,9);
  Broek *tre = new Broek(1,2);
  
  vector<Broek> broekListe;
  broekListe.push_back(*en);
  broekListe.push_back(*to);
  broekListe.push_back(*tre);
  
  
  for (int i = 1; i < broekListe.size(); i++) {
      cout<< broekListe[i].finnTeller()<<"/"<<broekListe[i].finnNevner()<<endl;
    }
  
  broekListe.erase(broekListe.begin()+1);
  
  cout<<"\noppgave 2.b"<<endl;
  Broek *fire;
  Broek *fem;
  Broek *seks;
  
  
  
  Broek *broekTabell [3] = {fire, fem, seks};
  
  broekTabell[0] = new Broek(2,3);
  broekTabell[1] = new Broek(3,4);
  broekTabell[2] = new Broek(5,5);
 
  broekListe.push_back(*broekTabell[0]);
  broekListe.push_back(*broekTabell[1]);
  broekListe.push_back(*broekTabell[2]);
  
  for (int i = 1; i < broekListe.size(); i++) {
      cout<< broekListe[i].finnTeller()<<"/"<<broekListe[i].finnNevner()<<endl;
    }
  
  broekListe.erase(broekListe.begin()+1);
  

    return 0;
}

