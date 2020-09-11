#include "operations.h"
#include <iostream>
#include <fstream>
#include "MyString.h"
#include "string"
#include "sstream"
#include <vector>
#include <map>

void operations::openFile() {

    std::fstream inFile;
    MyString r;
    std::string line;
    std::string tempStr;
    std::string anotherStr;

    std::map<std::string, int> P;
    std::map<std::string, int> N;

    inFile.open("D:\\School\\SMU\\CS 2341\\20f-sent-an-ikhlaqahmad1\\IMDB Dataset.csv");

    if(!inFile.is_open()){
        std::cout << "File is not open!" << std::endl;
    }
    while (!inFile.eof()){
        std::getline(inFile, line, ',');
        //std::cout << line << std::endl << std::endl;
        std::stringstream ss(line);

        while(ss >> tempStr){
            anotherStr += tempStr + " ";
            if(tempStr == "positive"){
                wordCounter(P,anotherStr);
                anotherStr = "";
            }
            else if(tempStr == "negative"){
                wordCounter(N,anotherStr);
                anotherStr = "";
            }

        }


    }
    std::cout << std::endl << "This is positive" << std::endl << std::endl;
    for (auto p = P.begin(); p != P.end(); ++p) {
        std::cout << p->first << "    p   " << p->second << " times.\n";
    }

    std::cout << std::endl << "This is negative" << std::endl << std::endl;
    for (auto n = N.begin(); n != N.end(); ++n) {
        std::cout << n->first << "   n    " << n->second << " times.\n";
    }

}

void operations::wordCounter(std::map<std::string, int>& R, std::string str) {
    std::string t;

    std::istringstream ww(str);
    while(ww >> t){
        R[t]++;
    }

}