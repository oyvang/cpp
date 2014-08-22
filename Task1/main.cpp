/* 
 * File:   main.cpp
 * Author: gm
 *
 * Created on August 22, 2014, 2:19 PM
 */
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*
 * 
 */
int main(){
    const int antall = 5;
    int tempUnder =0;
    int tempBetween=0;
    int tempOver=0;
    double temp = 0;
    cout << "\nSkriv inn 5 temperaturer\n";
    for (int i = 0; i < antall; i++){ 
        cout <<"Temp nr "<< i << ": ";
        cin>>temp;
        if(temp<10){
            tempUnder=tempUnder+1;
        }
        else if(temp>20){
            tempOver=tempOver+1;
        }
        else{
            tempBetween = tempBetween+1;
        }
    }
   
cout << "\nTemp under 10 : " << tempUnder << endl;
cout << "Temp mellom 10-20 : " << tempBetween << endl;
cout << "Temp over 20 : " << tempOver << endl;
    
    return 0;
}

