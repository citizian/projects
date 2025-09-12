#include<iostream>
#include<string>
using namespace std;
template<class T>
class LNode{
    public:
    T data;
    LNode* next;
};
template<class T>
class DLNode{
    public:
    T data;
    DLNode* front;
    DLNode* next;
};
template<class T>
class mylinkqueue{
    public:
    LNode<T> *front;
    LNode<T> *rear;

    mylinkqueue(){
        front = nullptr;
        rear = nullptr;
    }

bool init(){
    this->front = new LNode<T>;
    if(!this->front) return false;

    this->front->next = nullptr;
    this->rear = this->front;
    return true;
};
bool destroy(){
    if(!this->front) return false;
    T t;
    while(!this->isempty()){
        this->dequeue(t);
    }
    delete(this->front);
    this->front = this->rear = nullptr;
    return true;
};
bool enqueue(T t){
    LNode<T> * node = new LNode<T>;
    if(!node) return false;
    node->data = t;
    node->next = nullptr;

    this->rear->next = node;
    this->rear = node;
    return true;
};
bool dequeue(T &t){
    if(this->isempty()) return false;
    LNode<T> * node = this->front->next;
    t = node->data;
    this->front->next = node->next;
    if(isempty()) rear = front;
    delete(node);
    return true;
};
bool isempty(){
    return this->front->next == nullptr;
};

void show(){
    
    if(this->isempty()){
        cout << "? It's empty..";
    }
    T t;
    while(!this->isempty()){
        this->dequeue(t);
        cout << t;
    }
    cout << endl;
}

};