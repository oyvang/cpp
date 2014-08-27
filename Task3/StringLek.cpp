/* 
 * File:   StringLek.cpp
 * Author: gm
 *
 * Created on August 27, 2014, 11:57 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
#include <stdio.h>
#include <string.h>

int main() {
    // a)
    string ord1("");
    string ord2 = "";
    string ord3 = "";
    cin >> ord1 >> ord2 >> ord3;
    // b)
    string setning = ord1 + " " + ord2 + " " + ord3 + "."; 
    // c)
    cout << "ord 1 : " <<ord1.size() << endl;
    cout << "ord 2 : " <<ord2.size()  << endl;
    cout << "ord 3 : " <<ord3.size()  << endl;
    cout << "setnig : " <<setning.size()  << endl;
    // d
    string setning2 = setning;
    // e
    setning2.replace(9,3,"xxx");
    cout << "setning 2: " << setning2 << endl;
    // f
    string begynnelsen = "";
    begynnelsen.append(setning2,0,5);
    cout << "Begynnelsen: " << begynnelsen << endl;
    // g)
    size_t finnOrd = setning.find("hallo");
    if(finnOrd != std::string::npos){
        cout<<"Fant ordet <hallo> på plass: " << finnOrd<<endl;         
    }else{
        cout<<"setning inneholder ikke ordet <hallo>"<<endl;
    }
    // h)
    int antFunnet = 0;
    finnOrd = setning.find("er");
    while (finnOrd!=std::string::npos)
    {
        antFunnet++;
        finnOrd = setning.find("er", finnOrd +1);
        
    }
    cout << "Fant " << antFunnet << " forekomster av <er> " << endl;
    
   
    return 0;
}

