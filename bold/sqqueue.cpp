#include<iostream>
using namespace std;

const int MAX_SIZE = 10;
typedef struct Squeue{
    int data[MAX_SIZE];
    int front;
    int rear;
    int op;
}Squeue;

void init(Squeue &sq){
    sq.front = 0;
    sq.rear = 0;
    sq.op = 0;
}
bool enqueue(Squeue &sq, int e){
    if(isfull(sq)) return false;
    sq.rear = (sq.rear+1)%MAX_SIZE;
    sq.data[sq.rear] = e;
    sq.op = 1;
    return true;
}
bool dequeue(Squeue &sq, int &e){
    if(isempty(sq)) return false;
    sq.front = (sq.front + 1)%MAX_SIZE;
    e = sq.data[sq.front];
    sq.op = 0;
    return true;
}
bool peek(Squeue &sq,int &e){
    if(isempty(sq)) return false;
    e = sq.data[(sq.front + 1)%MAX_SIZE];
    return true;
}
bool isempty(Squeue &sq){
    return (sq.rear == sq.front)&&(sq.op == 0);
}
bool isfull(Squeue &sq){
    return (sq.rear == sq.front ) &&(sq.op ==1);
}
void destroy(Squeue &sq){
    sq.front = sq.rear = sq.op = 0;
}

int main(){
    return 0;
}