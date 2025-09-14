#include<iostream>
using namespace std;

const int MAX_SIZE=100;
class mstring{
    public:
    char ch[MAX_SIZE];
    int length;
    void operator=(string);
};

void assignstr(mstring &str,char c){
    for(int i = 1;i<=str.length;i++){
        str.ch[i] = c;
    }
}
void strcopy(mstring &str,const mstring &ss){
    str.length = ss.length;
    for(int i = 1;i<=str.length;i++){
        str.ch[i] = ss.ch[i];
    }
}

void strconcat(mstring &str1, mstring &str2){
    for(int i = 1; i<=str2.length; i++){
        str1.ch[str1.length+i] = str2.ch[i];
    }
    str1.length = str1.length+str2.length;
}
void strclear(mstring &str){
    str.length = 0;
}
void substr(mstring &substr,const mstring &str,int pos,int len){
    substr.length = len;
    for(int i = 1;i<=len;i++){
        substr.ch[i] = str.ch[pos+i-1];
    }
}
int strindex(mstring &str,const mstring &tstr){
    if(tstr.length>str.length) return 0;
    int i=1,j=1;
    while(i<=str.length && j<=tstr.length){
        if(str.ch[i] == tstr.ch[j]){
            i++;
            j++;
        }else{
            i= i-j+2;
            j=1;
        }
    }
    if(j>tstr.length)
        return i-j+1;
    return 0;
}
int kmp(const mstring &str,const mstring &tstr,int*next){
    int i =1, j = 1;
    while(i<=str.length && j<=tstr.length){
        if(j==0 || str.ch[i] == tstr.ch[j]) {
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j>tstr.length)
        return i-j+1;
    return 0;
}

void mstring::operator=(string str){
    length = str.length();
    for(int i =1;i<=length;i++){
        ch[i]=str[i-1];
    }
}
void printstr(mstring &str){
    for(int i = 1;i<=str.length;i++){
        cout<<str.ch[i];
    }
    cout << endl;
}

int * getnextarr(mstring &str){
    int *next = (int *)malloc((str.length+1)*sizeof(int));
    next[0]=0;
    next[1]=0;
    next[2]=1;


    return next;
}


int main(){
    mstring str1;
    mstring str2;
    str1 = "abababcababcab";
    str2 = "ababc";
    int next[6] = {0,0,1,1,2,3};
    printstr(str1);
    printstr(str2);
    cout << kmp(str1,str2,next) << endl;
    return 0;

}