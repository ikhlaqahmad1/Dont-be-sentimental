#include <cassert>
#include <iostream>
#include "MyString.h"
using namespace std;


int sum (int a){
    return a * 2;
}


int main() {

    MyString h = "fnjsn f ";
    cout << h.getLength() << endl;

    MyString k;
     k = h;
    cout << k.getLength();

    MyString f = "Ikhlaq Ahmad ";
    MyString b = "kromwofipo";
    MyString p = f + b;

    cout << endl <<  p.c_str();


    cout <<  endl << p.substring(4, 1).c_str();


    assert(sum(2) == 4);
   return 0;
}