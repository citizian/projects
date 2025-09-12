#include "workermi.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {};

void Worker::Data() const
{
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, name);
    cout << "Enter employee ID: ";
    cin >> id;
    while (cin.get() != '\n') // clear the input buffer
        continue;
}

void Waiter::Set()
{
    cout << "Enter Waiter name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Category: Waiter" << endl;
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "Panache: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') // clear the input buffer
        continue;
}

std::string Singer::pv[Singer::Vtypes] = {
    "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"
};

void Singer::Set()
{
    cout << "Enter Singer name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: Singer" << endl;
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "Voice type: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout <<"Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << " ";
        if(i%4 == 3)
            cout << endl;
    }
    if(i% 4 != 0)
        cout << endl;
    cin >> voice;
    while (cin.get() != '\n') // clear the input buffer
        continue;
}

void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter SingingWaiter name: ";
    Worker::Get();
    Get();
}
void SingingWaiter::Show() const
{
    cout << "Category: SingingWaiter" << endl;
    Worker::Data();
    Data();
}