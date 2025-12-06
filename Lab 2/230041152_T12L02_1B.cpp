#include<iostream>
#include<string>
#include<stack>
#define pb push_back
#define sc stack<char>
using namespace std;

int requiredMoves(string str){
    sc s;
    int moves=0;
    for(char ch:str){
        if(ch=='(') s.push(ch);
        else{
            if(!s.empty() && s.top()=='(') s.pop();
            else moves++;
        }
    }
    return moves;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        cout<<requiredMoves(str)<<endl;
    }
    return 0;
}