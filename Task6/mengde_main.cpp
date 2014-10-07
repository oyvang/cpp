/* 
 * File:   mengde_main.cpp
 * Author: gm
 *
 * Created on October 2, 2014, 10:23 AM
 */

#include <iostream>

#include "mengde.h"

using namespace std;

/*
 * 
 */
int main() {
    int *enMengde = new int[3];
    int *enAnnenMengde = new int[5];
    enMengde[0] = 1;
    enMengde[1] = 3;
    enMengde[2] = 6;
    
    enAnnenMengde[0] = 8;
    enAnnenMengde[1] = 1;
    enAnnenMengde[2] = 7;
    enAnnenMengde[3] = 3;
    enAnnenMengde[4] = 4;
    
    mengde TOM;
    mengde A(enMengde, 3);
    mengde B(enAnnenMengde, 5);
    
    mengde C = A + 5;
    C = C + 1;
    mengde D = B + A;
    
    mengde F = D;
    
    cout << "TOM MENGDE = ";
    TOM.toString();
    cout << "A = ";
    A.toString();
    cout << "B = ";
    B.toString();
    cout << "C = ";
    C.toString();
    cout << "D = ";
    D.toString();
    cout << "F = ";
    F.toString();
    


    return 0;
}

