#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map<string,int> stu;
    pair<string,int> p1 = make_pair<>("yang",18);
    stu.insert(p1);
    cout << "age:" << stu.at("yang")<<endl;
    stu.erase("yang");
    cout << "is empty?" << stu.empty()<< endl;

    return 0;
}