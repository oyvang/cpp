/* 
 * File:   Hus.cpp
 * Author: gm
 * 
 * Created on August 28, 2014, 9:46 AM
 */

#include "Hus.h"
using namespace std;

Person::Person(const string &startNavn, const string &startAdresse, const string &startTelefon)
    :navn(startNavn), adresse(startAdresse), telefon(startTelefon)
{

}

Bud::Bud(long startPris, const Person &startBudgiver)
    :pris(startPris), budgiver(startBudgiver)
{

}

int Hus::husnrMaks=0;

Hus::Hus(int startMaksAntBud, const string& startAdresse, const Person& startEier)
    :husnr(husnrMaks+1),antallBud(0),maksAntBud(startMaksAntBud), adresse(startAdresse),eier(startEier),budene(new Bud[maksAntBud])
{
    husnrMaks++;
}
Hus::Hus(const Hus& original)
    : husnr(original.husnr), adresse(original.adresse),eier(original.eier),antallBud(original.antallBud),maksAntBud(original.maksAntBud),budene(new Bud[maksAntBud])
{
    for (int i = 0; i < antallBud; i++) {
        budene[i]=original.budene[i];
    }
}

void Hus::leggInnNyttBud(long pris, const Person& person)
{
    if(antallBud == maksAntBud){
        maksAntBud+=5;
        Bud *temp = new Bud[maksAntBud];
        for (int i = 0; i < antallBud; i++) {
            temp[i]=budene[i];
        }
        delete [] budene;
        budene = temp;

    }
    budene[antallBud] = Bud(pris, person);
    antallBud++;
    
}

bool Hus::finnBudNr(int indeks, long& pris, Person& budgiver) const
{
    if(indeks>antallBud){
        return false;
    }
    pris = budene[indeks].finnPris();
    budgiver = budene[indeks].finnBudgiver();
    return true;
}
bool Hus::finnHoyesteBud(long& pris, Person& budgiver) const
{
    
    if(antallBud == 0){
        pris = 0;
        return false;
    }

    pris = budene[0].finnPris();
    budgiver = budene[0].finnBudgiver();
    for (int i = 1; i < antallBud+1; i++) {
        if(budene[i].finnPris() > pris){
            pris = budene[i].finnPris();
            budgiver = budene[i].finnBudgiver();
        }

    }
    return true;
}


Hus::~Hus()
{
    delete [] budene;
    budene = 0;
}