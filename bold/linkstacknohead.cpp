#include<iostream>
using namespace std;

typedef struct SNode {
    int data;
    struct SNode * next;
}SNode,*LStack;

bool Init(LStack &ls){
    ls=nullptr;
    return true;
}

bool isEmpty(LStack &ls){
    if(!ls) return true;
    return false;
}

bool push(LStack &ls, int e){
    SNode * s = (SNode *)malloc(sizeof(SNode));
    if(!s) return false;
    s->data =e;
    s->next = ls;
    ls = s;
    return true;
}
bool pop(LStack &ls, int &e){
    if(ls==nullptr) return false;
    e = ls->data;
    SNode *p = ls;
    ls = ls->next;
    free(p);
    return true;
}
bool Destroy(LStack &ls){
    int e;
    while(ls){
        pop(ls,e);
    }
    ls = nullptr;
    return true;
}
bool getElem(LStack &ls, int &e){
    if(!ls) return false;
    e = ls->data;
    return true;
}

int main(){
    return 0;
}