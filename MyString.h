
#ifndef S20_PA01_SENTIMENTANALYSIS_MYSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_MYSTRING_H


#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>

class MyString {

private:
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-sting functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/


    char *cstr;
    int length;


public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    MyString();

    MyString(const char *);

    MyString(const MyString &);

    ~MyString();

    /**
     * Standard relational operators.  You are free to expand this
     * list if you'd like.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/
    MyString &operator=(const char *);

    MyString &operator=(const MyString &);

    MyString operator+(const MyString &);

    bool operator==(const char *);

    bool operator==(const MyString &);

    bool operator>(const MyString &);

    char &operator[](const int);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength() const;

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     **/
    MyString substring(int start, int numChars);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char *c_str();


    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::istream &operator>>(std::istream &, const MyString&);
    friend std::ostream &operator<<(std::ostream &, const MyString &);




    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.
    bool isSubstring(const MyString &argString);
};


#endif
#endif //S20_PA01_SENTIMENTANALYSIS_MYSTRING_H
