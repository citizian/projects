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
class Gloam
{
private:
    int glip;
    Frabjous fb;
public:
    Gloam(int g = 0, const char * s = "c++");
    Gloam(int g, const Frabjous & f);
    void tell();
};

Gloam::Gloam(int g = 0, const char * s) : glip(g), fb(s) {}
Gloam::Gloam(int g, const Frabjous & f) : glip(g), fb(f) {}
void Gloam::tell() {
    cout << "Gloam: " << glip << ", ";
    fb.tell();
    cout << endl;
}