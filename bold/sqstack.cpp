#include<iostream>
using namespace std;
const int MAX_SIZE = 10;
typedef struct SqStack{
    int data[MAX_SIZE];
    int top;
}SqStack;

void StackInit(SqStack & ss){
    for(int i =0;i<MAX_SIZE;i++){
        ss.data[i]=0;
    }
    ss.top = -1;
}

bool push(SqStack & ss, int e){
    if(ss.top == MAX_SIZE-1) return false;
    ss.top++;
    ss.data[ss.top] = e;
    return true;
}

bool pop(SqStack & ss, int &e){
    if(ss.top == -1) return false;
    e = ss.data[ss.top];
    ss.top--;
    return true;
}

int getElem(SqStack &ss){
    int e = ss.data[ss.top];
    return e;
}

int main(){
    int test[5] = {11,12,13,14,15};
    SqStack ss;
    StackInit(ss);
    for(int i = 0;i<5;i++){
        push(ss,test[i]);
    }
    cout << getElem(ss) << endl;
    for(int i = 0;i<5;i++){
        int r;
        pop(ss, r);
        cout << r << " "; 
    }
    cout << endl;
    return 0;
}