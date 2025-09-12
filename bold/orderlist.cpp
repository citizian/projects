#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*静态分配

const int MAX_SIZE = 10;
typedef struct {
    char elem[MAX_SIZE];
    int size;
}OrderList, *pOL;
bool InitOL(OrderList L){
    for(int i =0;i<MAX_SIZE;i++){
        L->elem[i=1]='a';
    }
    L->size = 0;
    return true;
}
*/

//动态分配
const int InitSize = 10;
typedef struct{
    char *elem;
    int size;
    int MAX_SIZE;
}OrderList, *pOL;

void InitOL(OrderList &L){
    L.elem = (char*)malloc(sizeof(char)*InitSize);
    for(int i =0;i<InitSize;i++){
        L.elem[i]='0';
    }
    L.size = 0;
    L.MAX_SIZE = InitSize;
}
void IncreaseSize(OrderList &L,int len){
    char* p = L.elem;
    L.elem = (char*)malloc((L.MAX_SIZE+len)*sizeof(char));
    for(int i=0;i<L.size;i++){
        L.elem[i] = p[i];
    }
    L.MAX_SIZE = L.MAX_SIZE+len;
    free(p);
}


bool DestroyOL(OrderList &L){
    free(L.elem);
    L.elem=nullptr;
    L.size=0;
    return true;
}
bool InsertElem(OrderList &L, int i, char c){
    if(i<1 || i>L.size || L.size >= L.MAX_SIZE) return false;
    for(int j = L.size; j >= i;j--){
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i-1] = c;
    L.size++;
    return true;
}
bool RemoveByIndex(OrderList &L, int i, char &c){
    if(i<1 || i>L.size) return false;
    c = L.elem[i-1];
    for(int j = i;j<L.size;j++){
        L.elem[j-1] = L.elem[j];
    }
    L.size--;
    return true;
}
int FindByValue(OrderList &L, const char &c){
    for(int i = 1; i <= L.size; i++){
        if(L.elem[i-1] == c)
            return i;
    }
    return -1;
}
bool FindByIndex(OrderList &L,int i,char &c){
    if(i<1 || i>L.size)
        return false;
    c =  L.elem[i-1];
    return true;
}
void printOL(OrderList &L){
    if(L.size>0){
        for(int i=0;i<L.size;i++){
            printf("%c, ",L.elem[i]);
        }
    }
    printf("\n");
}


int main(){
    OrderList L;
    InitOL(L);
    L.size=4;
    printOL(L);
    InsertElem(L,3,'y');
    printOL(L);
    return 0;
}