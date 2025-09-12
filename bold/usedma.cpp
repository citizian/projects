#include<iostream>
#include "dma.h"
int main(){
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "Displaying lacksDMA object balloon2:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Displaying hasDMA object map2:\n";
    cout << map2 << endl;
    return 0;
}