#include<iostream>
#include<string>
#include "brass.h"
const int CLIENTS = 4;
using namespace std;
int main(){
    Brass *p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;
    for (int i = 0; i < CLIENTS; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: ";
        cin >> tempbal;
        cout << "Enter 1 for Brass account or 2 for BrassPlus account: ";
        cin >> kind;
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double maxLoan, rate;
            cout << "Enter maximum loan amount: ";
            cin >> maxLoan;
            cout << "Enter interest rate: ";
            cin >> rate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, maxLoan, rate);
        }
        while(cin.get() != '\n') // clear the newline character from the input buffer
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for(int i = 0; i < CLIENTS; i++) {
        delete p_clients[i]; // clean up dynamically allocated memory
    }
    cout << "Done.\n";
    return 0;
}