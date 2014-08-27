/* 
 * File:   Vare.cpp
 * Author: gm
 * 
 * Created on August 27, 2014, 10:52 AM
 */

#include <iosfwd>
#include <string>
#include <iostream>

using namespace std;

const double moms = 1.25;

class Vare {
    public:
        Vare(std::string, int, double);
        std::string finnNavn() const;
        int finnVarenr() const;
        double finnPrisPrEnhet() const;
        double finnPrisUtenMoms(int kvantum);
        double finnPrisMedMoms(int kvantum);
        void settPris(double nyPris);       
    private:
        std::string varenavn;
        int varenr;
        double pris;
};
    
Vare::Vare (std::string varenavn, int varenr, double pris){
    this->varenavn = varenavn;
    this->varenr = varenr;
    this->pris = pris;
}

std::string Vare::finnNavn() const
{
    return varenavn;
}

int Vare::finnVarenr()const
{
    return varenr;
}
double Vare::finnPrisPrEnhet() const
{ 
    return pris;
}

double Vare::finnPrisUtenMoms(int kvantum)
{
    return pris * kvantum;
}
double Vare::finnPrisMedMoms(int kvantum)
{
   return (pris * moms) * kvantum; 
}

void Vare::settPris(double nyPris)
{
    pris = nyPris;
}

int main() {
const double kvantum = 2.5;
const double kilopris1 = 73.50;
const double kilopris2 = 79.60;
Vare enVare("Norvegia", 123, kilopris1);
cout << "Varenavn: " << enVare.finnNavn() << ", varenr: " << enVare.finnVarenr()
<< " Pris pr enhet: " << enVare.finnPrisPrEnhet() << endl;
double pris1 = enVare.finnPrisUtenMoms(kvantum);
double pris2 = enVare.finnPrisMedMoms(kvantum);
cout << "Kilopris: " << kilopris1 << endl;
cout << "Prisen for " << kvantum << " kg er " << pris1 << " uten moms" << endl;
cout << "Prisen for " << kvantum << " kg er " << pris2 << " med moms" << endl;
enVare.settPris(kilopris2);
cout << "Ny kilopris: " << enVare.finnPrisPrEnhet() << endl;
cout << "Prisen for " << kvantum << " kg er "
        << enVare.finnPrisUtenMoms(kvantum) << " uten moms" << endl;
cout << "Prisen for " << kvantum << " kg er "
<< enVare.finnPrisMedMoms(kvantum) << " med moms" << endl;
return 0;
}






