#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

struct Big
{
    double stuff[20000];

};

int main()
{
    Big * pb;
    pb = new(std::nothrow) Big[100000];
    if(pb == 0) {
        cout << "Caught the exception!\n";
        exit(EXIT_FAILURE);
    }
    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete[] pb;
    return 0;
}