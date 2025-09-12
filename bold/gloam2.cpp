#include <iostream>
#include <string>
using namespace std;
class Frabjous
{
private:
    string fab;
public:
    Frabjous(const char * s = "c++") : fab(s) { }
    virtual void tell() {cout << fab;}
};
class Gloam : private Frabjous
{
private:
    int glip;
public:
    Gloam(int g = 0, const char * s = "c++");
    Gloam(int g, const Frabjous & f);
    void tell();
};
Gloam::Gloam(int g, const char * s) : Frabjous(s), glip(g) {}
Gloam::Gloam(int g, const Frabjous & f) : Frabjous(f), glip(g) {}
void Gloam::tell() {
    cout << "Gloam: " << glip << ", ";
    Frabjous::tell();
    cout << endl;
}

