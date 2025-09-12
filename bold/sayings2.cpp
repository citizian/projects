#include<iostream>
#include<cstdlib>
#include<ctime>
#include "string1.hpp"
const int ArSize = 10; // array size
const int MaxLen = 81; // max length of string
int main(){
    using namespace std;
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
        String * shortest = &sayings[0]; // pointer to shortest saying
        String * first = &sayings[0]; // pointer to first alphabetically
        for(i = 1; i < total; i++) { // find shortest saying
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first) // find first alphabetically
                first = &sayings[i];
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(time(0));
        int choice =rand() % total;
        String * favorite = new String(sayings[choice]); // random favorite saying
        cout << "Random favorite saying:\n" << *favorite << endl;
        delete favorite; // release memory
    }
    else
        cout << "No sayings entered.\n";
    cout << "Bye.\n";
    return 0;
}