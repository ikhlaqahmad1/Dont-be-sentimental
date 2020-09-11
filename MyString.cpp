#include "MyString.h"
#include "istream"


//constructor
MyString::MyString() {
    cstr = nullptr;
    length = 0;
}

//overloaded constructor
MyString::MyString(const char *c_copy){
    this->length = strlen(c_copy);
    cstr = new char[length +1];

    for(int c = 0; c < length; c++){
        cstr[c] = c_copy[c];
    }
    cstr[length] = '\0';

}

//copy operator
MyString::MyString(const MyString& c) {

    this->length = c.length;
    cstr = new char[length+1];
    for(int d = 0; d < length; d++){
        cstr[d] = c.cstr[d];
    }
    cstr[length] = '\0';
}
MyString::~MyString() {
    delete [] cstr;
    length = 0;
}





MyString & MyString::operator=(const char * b) {

    if (this->cstr != b) {
        delete[] cstr;

        length = strlen(b);
        cstr = new char[length + 1];

        for (int j=0; j < length; j++) {
            cstr[j] = b[j];
        }
        cstr[length] = '\0';
    }

    return *this;
}

MyString & MyString::operator=(const MyString & d) {
    if (this != &d){
        delete [] cstr;
        length = d.getLength();
        cstr = new char[length + 1];

        for (int j=0; j < length; j++) {
            cstr[j] = d.cstr[j];
        }
        cstr[length] = '\0';
    }
    return *this;
}



MyString MyString::operator+(const MyString & v) {

    int len = length + v.getLength();
    char*    str = new char[len];

    for (int j=0; j < length; j++){
        str[j] = cstr[j];
    }

    for (int i=0; i < v.getLength(); i++){
        str[length+i] = v.cstr[i];
    }

    delete cstr;
    length = len;
    cstr   = str;
    return *this;

}


bool MyString::operator==(const char * n) {

    if(this->cstr != n) {
        return false;
    }
    else {
        return true;
    }
}

bool MyString::operator==(const MyString & o) {
    if(this->cstr != o.cstr){
        return false;
    }
    else
        return true;

}



bool MyString::operator>(const MyString & g) {
    return false;
}

char & MyString::operator[](const int a) {
    if(a > length){
        throw 1;
    }
    return cstr[a];
}

//std::ostream &operator<<(std::ostream &, const MyString &){

//}

std::istream &operator>>(std::istream & is, const MyString &s){
    char* c = new char[s.getLength()];
    is >> c;

    //s = MyString(c);
    delete[] c;
    return is;
}



int MyString::getLength() const {
    return this->length;
}

MyString MyString::substring(int start, int numChars) {


    char *sub = new char[numChars + 1];

    for(int c = 0; c <= numChars; c++){
        sub[c] = cstr[start + c];
    }

    sub[numChars] = '\0';
    return sub;
}

char * MyString::c_str() {
    return this->cstr;
}

bool MyString::isSubstring (const MyString& argString)
{
    if (length < argString.length)
        return false;

    for (int i = 0; i < length; i++)
    {
        int j = 0;
        int tempi = i;
        while ((j < argString.length) && (cstr[tempi] == argString.cstr[j]))
        {
            tempi++;
            j++;
        }

        if (j == argString.length)
            return true;
    }
    return false;
}