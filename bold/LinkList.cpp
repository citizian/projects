#include<iostream>
using namespace std;

//带头节点的单链表
typedef struct LNode{
    char data;
    struct LNode *next;
}LNode, *LinkList;

bool Init(LinkList  &L) {
    L = (LNode*)malloc(sizeof(LNode));
    L->next = nullptr;
    return true;
}

bool Destroy(LinkList &L){
    LinkList p = L->next;
    LNode * q = nullptr;
    while(p!=nullptr){
        q = p;
        p=p->next;
        free(q);
    }
    L->next = nullptr;
    return true;
}
//头插尾插
LinkList HeadInsert(LinkList &L,LNode *node){
    node->next = L->next;
    L->next = node;
    return L;
}
LinkList TailInsert(LinkList &L,LNode *node){
    LNode * p = L;
    while(p->next !=nullptr){
        p=p->next;
    }
    node->next=nullptr;
    p->next=node;
    return L;
}
//按序按值查找
LNode * GetElemI(LinkList L, int i){
    if(i<1)return nullptr;
    int j=0;
    LNode *p = L;
    while(p->next!=nullptr){
        p = p->next;
        j++;
        if(j==i){
            return p;
        }
    }
    return nullptr;
}
LNode * LocateElem(LinkList L, char c){
    LNode *p = L;
    while(p->next!=nullptr){
        p=p->next;
        if(p->data == c)
            return p;
    }
    return nullptr;
}

//按序前插后插
bool FrontInsert(LinkList &L, int i,LNode* node){
    if(i<1) return false;
    LNode *p=GetElemI(L,i);
    if(p)return false;
    node->next = p->next;
    p->next = node;
    char c = p->data;
    p->data = node->data;
    node->data = c;
    return true;

}
bool BehindInsert(LinkList &L,int i,LNode * node){
    if(i<1) return false;
    LNode *p = GetElemI(L,i);
    if(p)return false;
    node->next = p->next;
    p->next = node;
    return true;
}
//按序前删后删
bool DeleteNode(LinkList &L,LNode *p){
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
bool DeleteElemI(LinkList &L, int i){
    if(i<1) return false;
    LNode *p = GetElemI(L,i-1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}
void Nodeprint(LinkList &L){
    LNode * p=L;
    while(p->next!=nullptr){
        p=p->next;
        cout << p->data<<" ";
    }
    cout << endl;
}


int main(){
    LinkList LL;
    Init(LL);
    LNode *node1 = (LNode*)malloc(sizeof(LNode));
    node1->data = 'a';
    node1->next = nullptr;
    LNode *node2 = (LNode*)malloc(sizeof(LNode));
    node2->data = 'b';
    node2->next = nullptr;
    LNode *node3 = (LNode*)malloc(sizeof(LNode));
    node3->data = 'c';
    node3->next = nullptr;

    TailInsert(LL,node1);
    TailInsert(LL,node2);
    TailInsert(LL,node3);

    Nodeprint(LL);
    Destroy(LL);
        Nodeprint(LL);
    return 0;
}