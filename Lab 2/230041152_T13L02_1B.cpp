#include<iostream>
#include<string>
#include<stack>
#define sc stack<char>
using namespace std;

int totalSize(string str) {
    sc s;
    int length=0;
    for(char ch:str){
        if(ch=='(') s.push(ch);
        else{
            if(!s.empty() && s.top()=='('){
                s.pop();
                length++;
            }
        }
    }
    return length*2;
}

int main() {
    string str;
    cin>>str;
    cout << totalSize(str) << endl;
    return 0;
}
