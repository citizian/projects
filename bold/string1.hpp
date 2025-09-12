#include<iostream>
#ifndef String_HPP_
#define String_HPP_
using std::ostream;
using std::istream;
class String {
private:
    char *str; // pointer to string
    int len;   // length of string
    static int num_strings; // number of objects
    static const int CINLIM = 80; // input limit
public:
    String(const char *s); // constructor
    String(); // default constructor
    String(const String &st); // deep copy constructor
    ~String(); // copy constructor
    int length() const { return len; } // length of string

    String &operator=(const String &st); // assignment operator
    String &operator=(const char *s);
    char &operator[](int i);
    const char &operator[](int i) const;

    friend bool operator < (const String &st1, const String &st2);
    friend bool operator > (const String &st1, const String &st2);
    friend bool operator == (const String &st1, const String &st2);

    friend istream & operator>> ( istream &is, String &st);
    friend ostream & operator<< (ostream &os, const String &st);

    static int HowMany();
};
#endif