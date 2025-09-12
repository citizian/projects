#include<iostream>
#include"studentc.h"
using namespace std;
void set(Student & sa, int n);
const int pupils=3;
const int quizzes=5;
int main() {
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };
    int i;
    for(i = 0; i < pupils; i++) {
        set(ada[i], quizzes);
    }
    cout << "\nStudent List:\n";
    for(i = 0; i < pupils; i++) {
        cout << ada[i].Name() << endl;
    }
    cout << "\nResults:\n";
    for(i = 0; i < pupils; i++) {
        cout << ada[i];
        cout << "Average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    return 0;
}
void set(Student & sa, int n) {
    cout << "Enter the name of the student: ";
    getline(cin, sa);
    cout << "Enter " << n << " quiz scores for " << sa.Name() << ": ";
    for(int i = 0; i < n; i++) {
        cin >> sa[i];
    }
    while(cin.get() != '\n') // clear the input buffer
        continue;
}