#include<iostream>
#include<vector>
#define vi vector<int>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* topNode=NULL;
int cap;
int cnt=0;

void print(){
    vi v;
    Node* cur=topNode;
    while(cur){
        v.push_back(cur->data);
        cur=cur->next;
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
        if(i) cout<<" ";
    }
    cout<<endl;
}

void push(int key){ //1
    if(cnt==cap){
        cout<<"Overflow"<<endl;
        return;
    }
    Node* n=new Node{key,topNode};
    topNode=n;
    cnt++;
    print();
}

void pop(){ //2
    if(!topNode){
        cout<<"Underflow"<<endl;
        return;
    }
    Node* n=topNode;
    topNode=topNode->next;
    delete n;
    cnt--;
    print();
}

void isEmpty(){ //3
    if(cnt==0) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}

void isFull(){ //4
    if(cnt==cap) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}

void size(){ //5
    cout<<cnt<<endl;
}

void top(){ //6
    if(!topNode){
        cout<<"Underflow"<<endl;
        return;
    }
    cout<<topNode->data<<endl;
}

int main(){
    cin>>cap;
    int op;
    while(cin>>op && op!=-1){
        if(op==1){
            int v;
            cin>>v;
            push(v);
        }
        else if(op==2){
            pop();
        }
        else if(op==3){
            isEmpty();
        }
        else if(op==4){
            isFull();
        }
        else if(op==5){
            size();
        }
        else if(op==6){
            top();
        }
    }
    return 0;
}