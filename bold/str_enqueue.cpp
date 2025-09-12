#include<iostream>
#include"mylinkqueue.cpp"
#include<string>
using namespace std;

void str_enqueue(mylinkqueue &lq,string str){
    string s = "0";
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i]>='0' && str[i]<='9'){
            s = s + str[i];
        }else {
            lq.enqueue(s);
            s = str[i];
            lq.enqueue(s);
            s = "";
        }
    }
    lq.enqueue(s);
    lq.show();
}


int main(){
    cout<<"size of string"<<sizeof(string)<<endl;
    cout<<"size of char"<<sizeof(char)<<endl;

    cout << endl;
    return 0;
}