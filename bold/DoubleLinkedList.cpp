#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct DNode {
    ElemType data;
    DNode *next;
    DNode *prev;
}DNode, *DLinkList;
//初始化
void ListInit(DLinkList &dll){
    dll = (DNode *)malloc(sizeof(DNode));
    dll->data='0';
    dll->next=nullptr;
    dll->prev=nullptr;
}
//头插
bool HeadInsert(DLinkList & dll, DNode * s){
    if(dll->next){
        dll->next->prev = s;
    }
    s->prev = dll;
    s->next = dll->next;
    dll->next = s;
    return true;
}
//尾插
bool TailInsert(DLinkList &dll,DNode *s){
    DNode *p = dll;
    while(p->next){
        p = p->next;
    }
    s->prev = p;
    s->next = p->next;
    p->next = s;
    return true;
}

//索引查找值查找
//删
bool Delete(DLinkList &dll, DNode *s){
    if(s->next)
        s->next->prev=s->prev;
    s->prev->next=s->next;
    free(s);
    return true;
}
bool Destroy(DLinkList &dll){
    while(dll->next){
        Delete(dll,dll->next);
    }
    return true;
}
void DLLPrint(DLinkList &dll){
    DNode *p = dll;
    while(p->next){
        p=p->next;
        cout << p->data<<" ";
    }
    cout << endl;
}



int main(){

    DLinkList dll;
    ListInit(dll);
    cout << "creating Double Linked List..." <<endl;
    char c;
    cin >> c;
    DNode *p;
    while(c != '0'){
        p = (DNode*)malloc(sizeof(DNode));
        p->data = c;
        p->next = nullptr;
        p->prev = nullptr;
        HeadInsert(dll,p);
        cin >> c;
    }
    DLLPrint(dll);
    Destroy(dll);
    return 0;
}