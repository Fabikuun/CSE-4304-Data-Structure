#include<iostream>
#include<string>
#include<stack>
#define pb push_back
#define sc stack<char>
using namespace std;

bool match(char open, char close){
    return (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    sc s;
    bool notMatch=false;
    bool missing=false;
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        for(char ch : line){
            if(ch=='(' || ch=='{' || ch=='['){
                s.push(ch);
            }
            else if(ch==')' || ch=='}' || ch==']'){
                if(s.empty())  missing=true;
                else if(!match(s.top(), ch)){
                    notMatch=true;
                    s.pop();
                }
                else s.pop();
            }
        }
    }
    if(missing || !s.empty()) cout<<"Missing parentheses"<<endl;
    else if(notMatch) cout<<"Improper parenthesis"<<endl;
    else cout<<"No error"<<endl;
    return 0;
}