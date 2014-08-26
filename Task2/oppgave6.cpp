/* 
 * File:   oppgave6.cpp
 * Author: gm
 *
 * Created on August 26, 2014, 10:10 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
const int tabellLengde = 20;
int finnSum(const int *tabell, int antElementer);
   
    
int main() {
    
    int tabell[tabellLengde];
    
    for (int i = 0; i < tabellLengde; i++) {
        tabell[i] = i+1;

    }
    int *peker = tabell;
    int fraElement = 0, antElementer=0;
    cout << "Velg et element fra 1-20 vi skal summere fra" << endl;
    cin >> (fraElement);
    cout << "Velg antall elementer som skal summeres" << endl;
    cin >> antElementer;
    fraElement = fraElement - 1;
    antElementer = antElementer - 1;
    *peker = *(peker+(fraElement));
    if(*peker+antElementer>tabellLengde){
        cout << "Tabellen er ikke " << *peker+antElementer << " elementer lang" << endl;
    }else{
        cout << "Finner summen fra element: "<< fraElement+1 << " til "<< fraElement+antElementer<< endl;
        cout << " = " << finnSum(peker, antElementer) << endl;
    }
    return 0;
}

int finnSum(const int *tabell, int antElementer){
    cout << "test" << *tabell << endl;
    int sum = 0;
    int tilElement = *tabell+antElementer;
    int fraElement = *tabell -1;
    for (int i = fraElement; i < tilElement; i++) {
        if (i+1 >= tilElement){
            cout << *(tabell + i);
           sum += *(tabell + i); 
        }else{
        cout << *(tabell + i)<< " + ";
        sum += *(tabell + i);
        }
    }
   
    return sum;
}

