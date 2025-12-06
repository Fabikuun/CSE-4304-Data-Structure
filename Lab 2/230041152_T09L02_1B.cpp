#include<iostream>
#include<string>
#include<stack>
#define pb push_back
#define sc stack<char>
using namespace std;
int main(){
    string str;
    cin>>str;
    sc s;
    for(char ch : str){
        if(!s.empty() && s.top() == ch) s.pop();
        else s.push(ch);
    }
    string result="";
    while(!s.empty()){
        result=s.top()+result; //result+=s.top(); append kore, prepend na, important
        s.pop();
    }
    if(result.empty()) cout<<"Null"<<endl;
    else cout<<result<<endl;
    return 0;
}