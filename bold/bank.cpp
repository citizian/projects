#include<iostream>
#include <cstdlib>
#include<ctime>
#include "queue.hpp"

const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main(){
    using std::cin;
    using std::cout;
    using std::ios_base;
    using std::endl;

    srand(time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs); // line queue of customers
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;

    long cyclelimit = MIN_PER_HR * hours; // total cycles to simulate
    cout <<"Enter the average number of customers per hour: ";
    double perhour; // average number of customers per hour
    cin >> perhour;
    double min_per_cust; // average time between customers
    min_per_cust = MIN_PER_HR / perhour;

    Item temp; // temporary item for queue operations
    long turnaways = 0; // customers turned away
    long customers = 0; // total customers
    long served = 0; // customers served
    long sum_line = 0; // total line length
    int wait_time = 0; // time until next customer is served
    long line_wait = 0; // total wait time in line

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) { // new customer arrives
            if (line.isfull()) { // if queue is full
                turnaways++; // increment turnaways
            } else {
                customers++; // increment total customers
                temp.set(cycle); // set arrival time for customer
                line.enqueue(temp); // add customer to queue
            }
        }
        if (wait_time <= 0 && !line.isempty()) { // if no wait time and queue not empty
            line.dequeue(temp); // remove customer from queue
            wait_time = temp.ptime(); // set wait time to processing time
            line_wait += cycle - temp.when(); // update total wait time
            served++; // increment served customers
        }
        if (wait_time > 0) { // if there is a wait time
            wait_time--; // decrement wait time
        }
        sum_line += line.queuecount(); // update total line length
    }

    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.precision(2);
        cout << "average queue size: "
             << static_cast<double>(sum_line) / cyclelimit << endl;
        cout << " average wait time: "
             << static_cast<double>(line_wait) / served << " minutes" << endl;
    } else {
        cout << "No customers!" << endl;
    }
    return 0;
    
}

bool newcustomer(double x) {
    return (rand() * x / RAND_MAX < 1); // returns true if a new customer arrives
}
