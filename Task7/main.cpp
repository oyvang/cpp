/* 
 * File:   main.cpp
 * Author: gm
 *
 * Created on October 7, 2014, 8:20 AM
 */
#include <cstdlib> 
#include <iostream>
#include <iomanip> 
#include <cmath> 
#include "klasseTemplate.hpp"


using namespace std;


double round(double x, int prec){
double power = 1.0;
int i;
if (prec > 0){
    for (i = 0; i < prec; i++)
        power *= 10.0;
}else if (prec < 0){
    for (i = 0; i < prec; i++)
        power /= 10.0;
        if (x > 0){
            x = floor(x * power + 0.5) / power;
        }else if (x < 0){
            x = ceil(x * power - 0.5) / power;
            if (x == -0){
                x = 0;
            }
        }
}
return x;
}

template <class type>
bool isEqual(const type x, const type y){
    std::cout<<"    notDouble  ";
    if(x==y)return true;
    return false;
}


bool isEqual(const double x, const double y){
    std::cout<<"    isDouble  ";
        //cout<<fixed;
        //cout<< setprecision(5);
        const double tolerance = 0.00001;
        const double diff = abs(x-y);
        double rDiff = round(diff,6); //må brukes for de klarer ikke å runde av double riktig
        //cout<<"diff"<<diff<<endl;
        //cout<<"rDiff "<<rDiff;
        if(rDiff<tolerance && rDiff>-tolerance)return true;
            return false;
}



int main() {

//OPPGAVE 1    
    
    cout << "OPPGAVE 1"<<endl;
    int a = 5;//sammenligner ned denne
    int b = 6;
    int c = a;

    cout<<"  sammenligner int verdier"<<endl;
    cout<<"a=b? "<<isEqual(a,b)<<" - skal være false"<<endl;
    cout<<"a=c? "<<isEqual(a,c)<<" - skal være true"<<endl;
    
    double d = 5.00001; //sammenligner med denne
    double e = 5.00002;
    double f = 5.00000;
    double g = 5.000019;
    double h = 5.000001;
    cout<<"  sammenligner double verdier"<<endl;
    cout<<"d=e? "<<isEqual(d,e)<<" - skal være false"<<endl;
    cout<<"d=f? "<<isEqual(d,f)<<" - skal være false"<<endl;
    cout<<"d=g? "<<isEqual(d,g)<<" - skal være true"<<endl;
    cout<<"d=g? "<<isEqual(d,h)<<" - skal være true"<<endl;
     
//OPPGAVE 2    
    cout << "\nOPPGAVE 2"<<endl;
    Broek A(4,40);
    Broek B(5,2);
    Broek C(6,3);
    Broek D(0,2);
    Broek E(1,4);
    
    Tabell<Broek> tabell;
    tabell.settVerdi(A);
    tabell.settVerdi(B);
    tabell.settVerdi(C);
    tabell.settVerdi(D);
    tabell.settVerdi(E);
    
    cout<<"  tabell før sortering"<<endl;
    for (int i = 0; i < 5; i++) { 
       cout<<"    index: "<<i<< " - verdi: " << tabell.finnVerdi(i).finnTeller()<<"/"<<tabell.finnVerdi(i).finnNevner()<<endl;

    }
    
    tabell.sorter();
    
   cout<<"  tabell etter sortering"<<endl;
    for (int i = 0; i < 5; i++) {
        cout<<"    index: "<<i<< " - verdi: " << tabell.finnVerdi(i).finnTeller()<<"/"<<tabell.finnVerdi(i).finnNevner()<<endl;

    }
   
   cout<<"    tabell på index[2] = "<<tabell[2].finnTeller()<<"/"<<tabell[2].finnNevner()<<endl;

//OPPGAVE 3
   cout<<"\nOPPGAVE 3"<<endl;
  Par<double, int> p1(3.5, 14); 
  Par<double, int> p2(2.1, 7); 
  cout << "  p1: " << p1.getFirstElement() << ", " << p1.getSecondElement() << endl; 
  cout << "  p2: " << p2.getFirstElement() << ", " << p2.getSecondElement() << endl; 
  if (p1 > p2) cout << "  p1 er størst\n"; 
  else cout << "  p2 er størst\n"; 
  Par<double, int> sum = p1 + p2; 
  cout << "  Sum: " << sum.getFirstElement() << ", " << sum.getSecondElement() << endl; 

    /* Utskrift: 
    p1: 3.5, 14 
    p2: 2.1, 7 
    p1 er størst her sammenligner vi 3.5+14 (=17.5) med 2.1+7 (=9.1) 
    Sum: 5.6, 21 første element i summen er lik 3.5+2.1, andre er lik 14+7 
    */
    
    
    

    return 0;
}

