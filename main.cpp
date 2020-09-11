#include <iostream>
#include "string"
#include <fstream>
#include "operations.h"
#include "MyString.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::ofstream fout("output01.txt");
    fout << "Hello "<< std::endl;
    fout.close();

    operations k;
    k.openFile();

    return 0;
}
