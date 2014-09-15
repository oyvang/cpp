/* 
 * File:   main.cpp
 * Author: gm
 *
 * Created on September 2, 2014, 11:13 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

const int antLin = 5;
const int antKol = 3;

double gjennomsnitt(double [], int);
void totalGjennomsnitt (double [antLin][antKol]);
void linjeGjennomsnitt (double [antLin][antKol], int);
void kolonneGjennomsnitt(double [antLin][antKol], int);



int main() {
double tabell[antLin][antKol];
int tall = 1;
for (int linjeIndeks = 0; linjeIndeks < antLin; linjeIndeks++) {
    for (int kolonneIndeks = 0; kolonneIndeks < antKol; kolonneIndeks++) {
        tall++;
        tabell[linjeIndeks][kolonneIndeks] = tall;
    }
}
for(int i=0; i<antLin; i++){
    for(int j=0; j<antKol; j++){
        cout << tabell[i][j]  << "  ";
    }
    cout << endl;
}
int linje = 0;
cout<<"Skriv inn hvilken linje du vil regen gjennomsnitt av (1-" <<antLin<<")" <<endl;
cin >> linje;
linje--;

int kol = 0;
cout<<"Skriv inn hvilken kolonne du vil regen gjennomsnitt av (1-" <<antKol<<")" <<endl;
cin >> kol;
kol--;

linjeGjennomsnitt(tabell,linje);

kolonneGjennomsnitt(tabell,kol);

totalGjennomsnitt(tabell);



    return 0;
}

//Oppgave 1a
void totalGjennomsnitt (double tabell[antLin][antKol]){
    double sum = 0;
    for (int i = 0; i < antLin; i++) {
        sum+= gjennomsnitt(tabell[i], antKol);
    }
    sum = sum/antLin;
    cout<<"Total gjennomsnitt = " << sum << endl;

}
//oppgave 1b
void linjeGjennomsnitt (double tabell[antLin][antKol],int linje){
    double sum = 0; 
    sum = gjennomsnitt(tabell[linje], antKol);
    cout<<"Gjennomsnitt av linje: "<<linje+1<<" = " << sum << endl;  
}
//oppgave 1c
void kolonneGjennomsnitt (double tabell[antLin][antKol], int kol){
    double sum = 0; 
    double temp[antLin];
    for (int i = 0; i < antLin; i++) {
        temp[i] = tabell[i][kol];
    }

    sum = gjennomsnitt(temp, antLin);
    cout<<"Gjennomsnitt av kolonne: "<<kol+1<<" = " << sum << endl;  
}

//oppgave 1
double gjennomsnitt (double tabell[], int lengde){
    double sum = 0;
    for (int i = 0; i < lengde; i++) {
        sum += tabell[i];
    }
    return sum/lengde; 
}

