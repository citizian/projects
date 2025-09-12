#include<iostream>
#include "string1.hpp"
const int ArSize = 10; // array size
const int MaxLen = 81; // max length of string

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    String name; // default constructor
    cout << "Hi, what's your name?\n";
    cin >> name; // input name
    cout << name << ", please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";
    String sayings[ArSize]; // array of strings
    char temp[MaxLen]; // temporary storage
    int i; // index for array
    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen); // get input
        while (cin && cin.get() != '\n') // clear input buffer
            continue;
        if (!cin || temp[0] == '\0') // check for empty line or EOF
            break;
        else
            sayings[i] = temp; // assign to array
    }
    int total = i; // total sayings entered
    if (total > 0) {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << i + 1 << ": " << sayings[i] << endl; // output
        int shortest = 0; // index of shortest saying
        int first = 0;
        for(i = 1; i < total; i++) { // find shortest saying
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first]) // find first alphabetically
                first = i;
        }
        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany()
             << " String objects. Bye.\n";
    }else
        cout << "No sayings entered.\n";
    return 0;
}