#ifndef QUEUE_HPP_
#define QUEUE_HPP_

class Customer {
private:
    long arrive; // arrival time for customer
    int processtime; // processing time for customer
public:
    Customer() { arrive = processtime = 0; } // default constructor
    void set(long when); // set arrival time and processing time
    long when() const { return arrive; } // return arrival time
    int ptime() const { return processtime; } // return processing time
};

typedef Customer Item; // define Item as Customer

class Queue {
private:
    struct Node { // node structure for linked list
        Item item; // item in the node
        Node *next; // pointer to next node
    };
    enum { Q_SIZE = 10 }; // maximum size of the queue
    Node *front; // pointer to front of the queue
    Node *rear; // pointer to rear of the queue
    int items; // current number of items in the queue
    const int qsize; // maximum size of the queue
    Queue(const Queue & q) : qsize(0) {} // prevent copying
    Queue & operator=(const Queue & q) { return *this; } // prevent assignment
public:
    Queue(int qs = Q_SIZE); // constructor with default size
    ~Queue(); // destructor
    bool isempty() const; // check if the queue is empty
    bool isfull() const; // check if the queue is full
    int queuecount() const; // return number of items in the queue
    bool enqueue(const Item & item); // add item to the queue
    bool dequeue(Item & item); // remove item from the queue
};
#endif