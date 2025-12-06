#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool bracketchecker(string str){
    stack<char>stack;
    for(int i=0;i<str.length();i++){
        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            stack.push(str[i]);
        }
        else if(!stack.empty()){
            if(str[i]==')'){
                if(stack.top()=='(')
                stack.pop();
                else return false;
            }
            else if(str[i]=='}'){
                if(stack.top()=='{')
                stack.pop();
                else return false;
            }
            else if(str[i]==']'){
                if(stack.top()=='[')
                stack.pop();
                else return false;
            }
            else continue;
        }
        else if(stack.empty() && (str[i]==')' || str[i]=='}'|| str[i]==']'))
        return false;
        else continue;
    }
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin,str);
        if(bracketchecker(str)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}