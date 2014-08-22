//
// tallfil.cpp
//
// Programmet leser tall fra fil og skriver summen av tallene til skjermen.
//
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void lesInnTemp(double temp[], int nrOfTemps);


int main() {

    int nrOfTemps = 5;
    double temp[nrOfTemps];
    lesInnTemp(temp,nrOfTemps); 

return 0;
}


void lesInnTemp(double temp[], int nrOfTemps) {
    const char filename[] = "tempfile.dat";
    ifstream file;

    file.open(filename); 
    if (!file) {
    cout << "Can not find file!" << endl;
    exit(EXIT_FAILURE); 
    }
    
    for (int i = 0; i < nrOfTemps; i++) {
        file >> temp[i];
    }
    file.close();
    
    int tempUnder= 0;
    int tempBetween = 0;
    int tempOver = 0;

    for (int i = 0; i < nrOfTemps; i++){       
        if(temp[i]<10){
            tempUnder=tempUnder+1;
        }
        else if(temp[i]>20){
            tempOver=tempOver+1;            
        }
        else{
            tempBetween=tempBetween+1;
        }
    }
    
    cout << "Temp under 10 : " << tempUnder << endl;
    cout << "Temp mellom 10-20 : " << tempBetween << endl;
    cout << "Temp over 20 : " << tempOver << endl;

}