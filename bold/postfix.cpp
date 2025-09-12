#include<iostream>
#include<string>
using namespace std;


typedef struct LNode{
    char data;
    struct LNode * next;
}LNode, *LStack;

bool init(LStack &ls){
    ls=nullptr;
    return true;
}
bool push(LStack &ls, char e){
    LNode * s = (LNode *)malloc(sizeof(LNode));
    if(!s) return false;
    s->data =e;
    s->next = ls;
    ls = s;
    return true;
}
bool pop(LStack &ls, char &e){
    if(ls==nullptr) return false;
    e = ls->data;
    LNode *p = ls;
    ls = ls->next;
    free(p);
    return true;
}
bool destroy(LStack &ls){
    char e;
    while(ls){
        pop(ls,e);
    }
    ls = nullptr;
    return true;
}
bool getElem(LStack &ls, char &e){
    if(!ls) return false;
    e = ls->data;
    return true;
}


string topostfix(string yourstr){
    LStack ls;
    init(ls);
    string str = yourstr;
    string res = "";
    int length = str.length();
    char c;
    string s = "";
    for(int i=0;i<length;i++){
        if(str[i]<='9' && str[i] >='0'){
            s = s + str[i];
        }else {
            res = res + s + " ";
            s = "";
            if(!getElem(ls,c)){
                push(ls,str[i]);
            }else{
                if(str[i] =='+' || str[i] =='-'){
                    while(pop(ls,c)){
                        res = res + c + " ";
                    }
                }
                if(str[i] == '*' || str[i] == '/'){
                    while(c == '*' || c =='/'){
                        pop(ls,c);
                        res = res + c + " ";
                        getElem(ls,c);
                    }
                }
                push(ls,str[i]);
            }
        }
    }
    res = res + s + " ";
    while(pop(ls,c)){
        res = res +c + " ";
    }
    destroy(ls);
    return res; ;
}

int main(){
    string yourstr;
    cout << "Please input your infix expression:" << endl;
    cin >> yourstr;
    cout << "The postfix expression is:" << endl;
    cout << topostfix(yourstr) << endl;

    return 0;
}