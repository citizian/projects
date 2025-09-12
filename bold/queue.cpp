#include "queue.hpp"
#include <cstdlib> // for rand() and srand()
Queue::Queue(int qs) : qsize(qs){
    front = rear = nullptr; // Initialize front and rear pointers to nullptr
    items = 0; // Initialize the number of items in the queue to 0
    // Initialize the queue with a maximum size
}
Queue::~Queue() {
    Node *temp;
    while (front != nullptr) { // While there are nodes in the queue
        temp = front; // Store the current front node
        front = front->next; // Move front to the next node
        delete temp; // Delete the old front node
    }
}
bool Queue::isempty() const {
    return items == 0; // Check if the number of items is 0
}
bool Queue::isfull() const {
    return items == qsize; // Check if the number of items is greater than or equal to the maximum size
}
int Queue::queuecount() const {
    return items; // Return the current number of items in the queue
}

bool Queue::enqueue(const Item & item) {
    if (isfull()) {
        return false; // If the queue is full, return false
    }
    Node *add = new Node; // Create a new node
    add->item = item; // Set the item in the new node
    add->next = nullptr; // Initialize the next pointer to nullptr
    if (front == nullptr) { // If the queue is empty
        front = add; // Set both front and rear to the new node
    } else {
        rear->next = add; // Link the old rear to the new node
    }
    rear = add; // Update the rear pointer to the new node
    items++; // Increment the number of items in the queue
    return true; // Return true indicating successful enqueue
}

bool Queue::dequeue(Item & item) {
    if (front == nullptr) {
        return false; // If the queue is empty, return false
    }
    item = front->item; // Get the item from the front node
    items--; // Decrement the number of items in the queue
    Node *temp = front; // Store the current front node
    front = front->next; // Move front to the next node
    delete temp; // Delete the old front node
    if (items == 0) { // If the queue is now empty
        rear = nullptr; // Set rear to nullptr as well
    }
    return true; // Return true indicating successful dequeue
}

void Customer::set(long when) {
    arrive = when; // Set the arrival time
    processtime = rand() % 3 + 1; // Set processing time to a random value between 1 and 3
}