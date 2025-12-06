#include<iostream>
#include<stack>
#include<vector>
#define si stack<int>
#define vi vector<int>
#define pb push_back
using namespace std;

void Queue(si &s1){
    if(s1.empty()){
        cout<<"Size:0 Elements: Null"<<endl;
        return;
    }
    si reverse;
    while(!s1.empty()){
        reverse.push(s1.top());
        s1.pop();
    }
    int size=reverse.size();
    cout<<"Size:"<<size<<" Elements: ";
    while(!reverse.empty()){
        cout<<reverse.top()<<" ";
        s1.push(reverse.top());
        reverse.pop();
    }
    cout<<endl;
}

int main(){
    int N, q;
    cin>>N>>q;
    si s1, temp;
    while(q--){
        int type;
        cin>>type;
        switch(type){
            case 1:{
                int x;
                cin>>x;
                if(s1.size()>=N){
                    cout<<"Size:"<<s1.size()<<" Elements: Overflow!"<<endl;
                    break;
                }
                s1.push(x);
                Queue(s1);
                break;
            }
            case 2:{
                if(s1.empty()){
                    Queue(s1);
                    break;
                }
                while(!s1.empty()){
                    temp.push(s1.top());
                    s1.pop();
                }
                temp.pop();
                while(!temp.empty()){
                    s1.push(temp.top());
                    temp.pop();
                }
                Queue(s1);
                break;
            }
            default:{
                break;
            }
        }
    }
    return 0;
}