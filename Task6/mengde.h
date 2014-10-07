/* 
 * File:   mengde.h
 * Author: gm
 *
 * Created on October 1, 2014, 3:26 PM
 */

#ifndef MENGDE_H
#define	MENGDE_H

#include <iostream>
using namespace std;

class mengde {
public:
    
    mengde();//oppgave; a
    mengde(const int *tabell, int tabellstr);
    mengde(const int antallTall); //oppgave b
    mengde(const mengde &original); //oppgave b
    ~mengde();
    mengde operator+(const mengde &denAndre); //oppgave c
    mengde operator+(const int heltall); //oppgave d
    mengde &operator=(const mengde &original); //oppgave e
    int GetAntallTall() const {return antallTall;}
    int GetSummen() const { return summen; }
    int GetTabellstr() const {return tabellstr;}
    void  toString() const;


    
private:
    int tabellstr;
    int antallTall;
    int *heltallstabell;
    int summen;
};

#endif	/* MENGDE_H */

