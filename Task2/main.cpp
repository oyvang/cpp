/* 
 * File:   main.cpp
 * Author: gm
 *
 * Created on August 24, 2014, 12:58 PM
 */


#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;
    
    cout << "\n Oppgave 1a" << endl;
    cout << "Adressen til i  - " << &i << endl;
    cout << "Adressen til *p - " << &*p << endl;
    cout << "Adressen til j  - " << &j << endl;
    cout << "Adressen til *q - " << &*q << endl;
    
    cout << "\n Oppgave 1b" << endl;
    *p = 7;
    *q += 4;  // i+=4 -> 3+5 =4
    *q = *p + 1;  // 7+1 = 8
    p = q;
    cout << *p << " " << *q << endl;
    cout << "Variabel: i  - " << i << endl;
    cout << "peker: *p - " << *p << endl;
    cout << "Variabel: j  - " << j << endl;
    cout << "peker: *q - " << *q << endl;
    
    
    /* Oppgave 4*/
    int a = 5;
    int& b = a; //sier at b skal ha samme minnelokasjon som a
    int *c; // Burde initialiseres men ikke nødvendig
    c = &b; // sier at c skal peke til minnelokasjonen til b
    a = b + *c; // denne er unødvendig når vi endrer b under men gir a verdien 10
    b = 2; // Kunne lige godt stå a = 2 på grunn av samme minnelokasjon.
    
   /*Oppgave 5*/
    double tall = 1;
    double *peker = &tall;
    double& tall2 = tall;
    
    tall = 2;
    *peker = 3;
    tall2 = 4;
    
            
    
    
    
    
    return 0;
}

