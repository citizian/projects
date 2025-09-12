#include<iostream>
#include "tabtenn0.hpp"
using std::cout;

int main(){
    TableTennisPlayer player1("Tara", "Boomdea", true);
    TableTennisPlayer player2("Mallory", "Duck", false);
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player2.Name();
    if (player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player2.ResetTable(true);
    cout << "Now ";
    player2.Name();
    if (player2.HasTable()) 
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    return 0;
}