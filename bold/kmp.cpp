#include<iostream>
#include<string>
using namespace std;

int * getnext(string s1){
    //s1=abaabc;
    int * next = (int*)malloc(sizeof(int) * s1.length());
    next[0]=-1;
    next[1]=0;
    for(int i = 2;i<s1.length();i++){
        int j = 0

    }
    return next;

}

int kmp(string s1,string s2,int *next){
    int i=0,j=0;
    while( i<s1.length() && j<s2.length()){
        if(j ==0 || s1[i] == s2[j]){
            i++;
            j++;
        }else{
            j = next[j-1];
        }
    }
    if(j==s2.length()){
        return i-j;
    }
    return 0;
}

int main(){
    string str1="ababababc";
    string str2 = "ababc";
    int next[5]={-1,0,1,2,0};
    cout << kmp(str1,str2,next) << endl;
    return 0;
}