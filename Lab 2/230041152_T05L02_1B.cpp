#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin,str);
        stack<char> s;
        for(int i=0; i<str.length(); i++){
            s.push(str[i]);
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}