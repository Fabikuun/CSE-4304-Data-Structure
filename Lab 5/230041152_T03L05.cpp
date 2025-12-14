#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node* prev;
}Node;

Node* head=NULL;
Node* tail=NULL;
int cnt=0;

void push_front(int key){ //1
    Node* n=new Node{key, head, NULL};
    if(head) head->prev=n;
    head=n;
    if(!tail) tail=n;
    cnt++;
}

void push_back(int key){ //2
    Node* n=new Node{key, NULL, tail};
    if(!tail){
        head=tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
    cnt++;
}

int pop_front(){ //3
    if(!head){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int val=head->data;
    Node* n=head;
    head=head->next;
    if(head) head->prev=NULL;
    else tail=NULL;
    delete n;
    cnt--;
    return val;
}

int pop_back(){ //4
    if(!tail){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int val=tail->data;
    Node* n=tail;
    tail=tail->prev;
    if(tail) tail->next=NULL;
    else head=NULL;
    delete n;
    cnt--;
    return val;
}

int size(){ //5
    return cnt;
}

void print(){
    if(!head){
        cout<<"Empty"<<endl;
        return;
    }
    Node* cur=head;
    while(cur){
        cout<<cur->data;
        if(cur->next) cout<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

int main(){
    int op;
    while(cin>>op){
        if(op==1){
            int v;
            cin>>v;
            push_front(v);
            print();
        }
        else if(op==2){
            int v;
            cin>>v;
            push_back(v);
            print();
        }
        else if(op==3){
            int x=pop_front();
            if(x!=-1) print();
        }
        else if(op==4){
            int x=pop_back();
            if(x!=-1) print();
        }
        else if(op==5){
            cout<<size()<<endl;
        }
        else if(op==6){
            cout<<"Exit"<<endl;
            break;
        }
    }
    return 0;
}