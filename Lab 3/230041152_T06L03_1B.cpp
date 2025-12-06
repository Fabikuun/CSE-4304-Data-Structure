#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    deque<string> dq;
    dq.push_back("");
    bool atFront=false;
    for(char c:str){
        if(c=='['){
            atFront = true;
            dq.push_front("");
        }
        else if(c==']'){
            atFront = false;
            dq.push_back("");
        }
        else{
            if(atFront) dq.front() += c;
            else dq.back() += c;
        }
    }
    for(const string& s:dq){
        cout<<s;
    }
    cout<<endl;
    return 0;
}