#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* frontNode=NULL;
Node* rearNode=NULL;
int cap;
int cnt=0;

void printQueue(){
    Node* cur=frontNode;
    while(cur){
        cout<<cur->data;
        if(cur->next) cout<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

void enqueue(int key){ //1
    if(cnt==cap){
        cout<<"EnQueue: Overflow"<<endl;
        return;
    }
    Node* n=new Node{key,NULL};
    if(!rearNode){
        frontNode=rearNode=n;
    }
    else{
        rearNode->next=n;
        rearNode=n;
    }
    cnt++;
    cout<<"EnQueue: ";
    printQueue();
}

void dequeue(){ //2
    if(!frontNode){
        cout<<"DeQueue: Underflow"<<endl;
        return;
    }
    Node* n=frontNode;
    frontNode=frontNode->next;
    if(!frontNode) rearNode=NULL;
    delete n;
    cnt--;
    cout<<"DeQueue: ";
    printQueue();
}

void isEmpty(){ //3
    if(cnt==0) cout<<"isEmpty: True"<<endl;
    else cout<<"isEmpty: False"<<endl;
}

void isFull(){ //4
    if(cnt==cap) cout<<"isFull: True"<<endl;
    else cout<<"isFull: False"<<endl;
}

void size(){ //5
    cout<<"Size: "<<cnt<<endl;
}

void front(){ //6
    if(!frontNode){
        cout<<"Front: Underflow"<<endl;
        return;
    }
    cout<<"Front: "<<frontNode->data<<endl;
}

int main(){
    cin>>cap;
    int op;
    while(cin>>op && op!=-1){
        if(op==1){
            int v;
            cin>>v;
            enqueue(v);
        }
        else if(op==2) dequeue();
        else if(op==3) isEmpty();
        else if(op==4) isFull();
        else if(op==5) size();
        else if(op==6) front();
    }
    cout<<"Exit"<<endl;
    return 0;
}