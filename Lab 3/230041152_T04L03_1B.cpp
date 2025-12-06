#include<iostream>
#include<queue>
#include<string>
#define pb push_back
using namespace std;

int main(){
    string S,T;
    cin>>S>>T;
    int lenS=S.length(), lenT=T.length();
    if(lenS!=lenT){
        cout<<"No"<<endl;
        return 0;
    }
    if(S==T){
        cout<<"Yes. Rotation not needed"<<endl;
        return 0;
    }
    deque<char> dq;
    for(char c:S){
        dq.pb(c);
    }
    for(int i=1; i<=lenS; i++){
        char last=dq.back();
        dq.pop_back();
        dq.push_front(last);
        string newStr="";
        for(char c:dq){
            newStr+=c;
        }
        if(newStr==T){
            cout<<"Yes. After "<<i<<" clockwise rotations"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}