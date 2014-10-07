/* 
 * File:   mengde.cpp
 * Author: gm
 * 
 * Created on October 1, 2014, 3:26 PM
 */

#include "mengde.h"
#include <iostream>

using namespace std;

mengde::mengde():
    tabellstr(5), heltallstabell(new int[tabellstr]), antallTall(0),summen(0){
}

mengde::mengde(const int* tabell, int setTabellstr):
    heltallstabell(new int[setTabellstr]),tabellstr(setTabellstr), summen(0), antallTall(0){
    for (int i = 0; i < tabellstr; i++) {
        heltallstabell[i] = tabell[i];
        summen += tabell[i];
        antallTall++;
    }

}


mengde::mengde(const int setTabellstr):
    heltallstabell(new int[setTabellstr]),tabellstr(setTabellstr),antallTall(0),summen(0){
}
mengde::mengde(const mengde &original):
    heltallstabell(new int[original.tabellstr]),antallTall(original.antallTall),summen(original.summen),
    tabellstr(original.tabellstr){
        for (int i = 0; i < antallTall; i++) {
            heltallstabell[i] = original.heltallstabell[i];
        }
}

mengde mengde::operator +(const int heltall) {
    bool isTallinTabell = false;
    for (int i = 0; i < antallTall; i++) {
        if(heltallstabell[i]==heltall){
            isTallinTabell = true;
        }
    }
    if(!isTallinTabell){
        if(tabellstr==antallTall){
            tabellstr+=5;
            int *temp = new int[tabellstr];
            for (int i = 0; i < antallTall; i++) {
                temp[i]=heltallstabell[i];
            }
            delete [] heltallstabell;
            heltallstabell = temp;
        }
        heltallstabell[antallTall] = heltall;  
        antallTall++;
        summen += heltall;
        cout << "alt ok, lagt til " << heltallstabell [antallTall-1]<< endl;
    }else{
        cout << "alt ok, men " << heltall<< " finnes i mengden fra før" << endl;
    }
 return *this;
}

mengde mengde::operator+(const mengde &denAndre) {
    mengde mengden(antallTall+denAndre.antallTall);
    for (int i = 0; i < antallTall; i++) {
        mengden.heltallstabell[i] = heltallstabell[i];
    }
    mengden.summen = summen;
    mengden.antallTall = antallTall;
    bool liktTall = false;
    for (int i = 0; i < denAndre.antallTall; i++) {
        for (int j = 0; j < antallTall; j++) {
            if(mengden.heltallstabell[j]==denAndre.heltallstabell[i]){
                liktTall = true;
                j=antallTall;
            }
        }
        if(!liktTall){
            mengden.heltallstabell[mengden.antallTall] = denAndre.heltallstabell[i];
            mengden.summen += mengden.heltallstabell[antallTall];
            mengden.antallTall++;
        }
        liktTall = false;
    }
  return mengden;
} 

mengde &mengde::operator=(const mengde &original) {
    heltallstabell[original.tabellstr]; 
    antallTall = original.antallTall;
    tabellstr = original.tabellstr;
    summen= original.summen;
  return *this;
} 

void mengde::toString() const {
    if(antallTall == 0){
        cout << "{}"<<endl;
    }else{
    /*cout <<"SUMMEN: "<< this->summen << endl;
    cout <<"TABELL STR: "<< this->tabellstr << endl;
    cout <<"ANTALL TALL: "<< this->antallTall << endl;*/
    cout << "{";
    for (int i = 0; i < this->antallTall; i++) {
        if(i+1==this->antallTall){
            cout <<this->heltallstabell[i] <<"}"<< endl;
        }else{
        cout << this->heltallstabell[i] << ",";
        }
    }
    }

}

mengde::~mengde()
{
    delete [] heltallstabell;
    heltallstabell = 0;
}


