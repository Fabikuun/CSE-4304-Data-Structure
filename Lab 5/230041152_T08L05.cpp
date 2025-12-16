#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* head=NULL;
Node* tail=NULL;

void insert_back(int key){
    Node* n=new Node{key,NULL};
    if(!head){
        head=tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}

void rearrange(){
    if(!head || !head->next) return;

    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;

    while(even && even->next){
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenHead;
}

void print(){
    Node* cur=head;
    while(cur){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    string s;
    while(cin >> s){
        if(s=="NULL") break;
        insert_back(stoi(s));
    }
    rearrange();
    print();
    return 0;
}