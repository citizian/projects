#include<cstring>
#include "string1.hpp"
using std::cout;
int String::num_strings = 0; // static member
String::String(const char *s) {
    len = std::strlen(s); // set size
    str = new char[len + 1]; // allocate storage
    std::strcpy(str, s); // initialize pointer
    num_strings++; // set object count
}
String::String() {
    len = 0; // default size
    str = new char[1]; // allocate storage
    str[0] = '\0'; // default string
    num_strings++; // set object count
}
String::String(const String &st) {
    num_strings++; // set object count
    len = st.len; // set size
    str = new char[len + 1]; // allocate storage
    std::strcpy(str, st.str); // copy string to new location
}
String &String::operator=(const String &st) {
    if (this == &st) // avoid self-assignment
        return *this;
    delete [] str; // release old storage
    len = st.len; // set size
    str = new char[len + 1]; // allocate new storage
    std::strcpy(str, st.str); // copy string to new location
    return *this; // return reference to this object
}
String &String::operator=(const char *s) {
    delete [] str; // release old storage
    len = std::strlen(s); // set size
    str = new char[len + 1]; // allocate new storage
    std::strcpy(str, s); // copy string to new location
    return *this; // return reference to this object
}
bool operator < (const String &st1, const String &st2) {
    return std::strcmp(st1.str, st2.str) < 0;
}
bool operator > (const String &st1, const String &st2) {
    return st2 < st1; // use the less than operator
}
bool operator == (const String &st1, const String &st2) {
    return std::strcmp(st1.str, st2.str) == 0; // compare strings
}
char &String::operator[](int i) {
    return str[i]; // return reference to character at index
}
const char &String::operator[](int i) const {
    return str[i]; // return const reference to character at index
}

String::~String() {
    --num_strings; // decrement object count
    delete [] str; // release storage
}
ostream &operator<<(ostream &os, const String &st) {
    os << st.str; // output string
    return os; // return reference to output stream
}
istream &operator>>(istream &is, String &st){
    char temp[String::CINLIM]; // temporary storage
    is.get(temp, String::CINLIM); // read input into temp
    if (is) { // if input is successful
        st = temp; // assign temp to String object
    }
    while (is && is.get() != '\n') // discard rest of line
        continue;
    return is; // return reference to input stream
}
int String::HowMany() {
    return num_strings; // return number of String objects
}