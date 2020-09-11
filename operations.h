#ifndef S20_PA01_SENTIMENTANALYSIS_OPERATIONS_H
#define S20_PA01_SENTIMENTANALYSIS_OPERATIONS_H
#include <iostream>
#include <string>
#include <map>
class operations{
private:

public:
    void openFile();
    void wordCounter(std::map<std::string, int>&, std::string);
};
#endif //S20_PA01_SENTIMENTANALYSIS_OPERATIONS_H
