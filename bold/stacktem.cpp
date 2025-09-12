#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using namespace std;

int main()
{
    Stack<string> st;
    char ch;
    string po;
    cout << "Please enter A to add a purchase order,\n"
         << "p to process a PO, or q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get() != '\n') // clear the input buffer
            continue;
        if (!isalpha(ch))
        {
            cout << '\a'; // alert for invalid input
            continue; // skip to next iteration
        }
        switch(ch)
        {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.push(po))
                    cout << po << " has been added.\n";
                else
                    cout << "Stack is full!\n";
                break;
            case 'P':
            case 'p':
                if (st.isEmpty())
                    cout << "stack already empty!\n";
                else
                {
                    st.pop(po);
                    cout << "PO # " << po << " popped\n";
                }
            default:
                cout << '\a'; // alert for invalid input
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "p to process a PO, or q to quit.\n";
    }
    cout << "Bye!\n";
    return 0;
}