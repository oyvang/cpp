//
// frafil.cpp
//
//
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void lesInnTemp(double temp[], int antall);


int main() {
    int antall = 5;
    double temp[antall];

    lesInnTemp(temp, antall);
    
    return 0;
}
void lesInnTemp(double temp[], int antall) {
    const char filnavn[] = "tempfil.dat";
    ifstream innfil;
    innfil.open(filnavn); 
    if (!innfil) { 
        cout << "Feil ved åpning av innfil." << endl;
        exit(EXIT_FAILURE); // uthopp fra programmet
    }
    
    for (int i = 0; i < antall; i++) {
        innfil >> temp[i];    
    }
    innfil.close();
    
    int tempUnder = 0;
    int tempBetween = 0;
    int tempOver = 0;
    
    for (int i = 0; i < antall; i++) {
        if(temp[i]<10){
            tempUnder=tempUnder+1;
        }
        else if(temp[i]>20){
            tempOver=tempOver+1;
        }
        else{
            tempBetween = tempBetween+1;
        }

    }
 
    cout << "Temp under 10 : " << tempUnder << endl;
    cout << "Temp mellom 10-20 : " << tempBetween << endl;
    cout << "Temp over 20 : " << tempOver << endl;
    
}