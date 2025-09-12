#include<iostream>
using namespace std;

typedef struct SNode{
    int data;
    struct SNode *next;
}SNode, *LStack;

void LStackInit(LStack &ls){
    ls = (SNode *) malloc(sizeof(SNode));
    ls->data = 0;
    ls->next = nullptr;
}

bool push(LStack &ls, int e){
    SNode *s = (SNode*)malloc(sizeof(SNode));
    if(!s) return false;
    s->data = e;
    s->next = ls->next;
    ls->next = s;
    return true;
}

bool pop(LStack &ls, int &e){
    if(!ls->next) return false;
    SNode *p=ls->next;
    e = p->data;
    ls->next = p->next;
    free(p);
    return true;
}
int getElem(LStack &ls){
    if(!ls->next) return 0;
    int e = ls->next->data;
    return e;
}
bool isEmpty(LStack & ls){
    if(ls->next) return true;
    return false;
}

int main(){
    return 0;
}