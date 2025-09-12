#include<iostream>
#include<cstdlib>
using namespace std;

const int MAX_SIZE = 10;
struct LNode{
    int data;
    struct LNode *next;
};

struct lqueue{
    LNode *head;
    LNode *tail;
    int length;
};

void init(lqueue &lq){
    lq.head = lq.tail = nullptr;
    lq.length=0;
}
bool enqueue(lqueue &lq, int e){
    if(isfull(lq)) return false;

    LNode * node = (LNode*)malloc(sizeof(LNode));
    if(node==nullptr) return false;
    node->data = e;
    node->next = nullptr;
    if(isempty(lq))
    {
    lq.tail = node;
    lq.head = node;
    }else{
        lq.tail->next = node;
        lq.tail = node;
    }
    lq.length++;
    return true;
}
bool dequeue(lqueue &lq, int &e){
    if(isempty(lq)) return false;
    e = lq.head->data;
    LNode * q = lq.head;
    lq.head = lq.head->next;
    free(q);
    lq.length--;
    if(isempty(lq)){
        lq.tail = nullptr;
    }
    return true;
}
bool isfull(lqueue &lq){
    return lq.length==MAX_SIZE;
}
bool isempty(lqueue &lq){
    return lq.length == 0;
}
bool getHead(lqueue &lq, int &e){
    if(isempty(lq)) return false;
    e = lq.head->data;
    return true;
}
bool destroy(lqueue &lq){
    int e;
    while(!isempty(lq)){
        dequeue(lq,e);
    }
    return true;
}

int main(){
    return 0;
}