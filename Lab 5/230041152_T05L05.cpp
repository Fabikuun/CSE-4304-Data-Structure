#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node* prev;
}Node;

Node* head1=NULL;
Node* tail1=NULL;
Node* head2=NULL;
Node* tail2=NULL;
Node* head3=NULL;
Node* tail3=NULL;

void insert_back(Node* &head, Node* &tail, int key){
    Node* n=new Node{key,NULL};
    if(!head){
        head=tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}

void intersection(){
    Node* p=head1;
    Node* q=head2;
    while(p && q){
        if(p->data==q->data){
            insert_back(head3,tail3,p->data);
            p=p->next;
            q=q->next;
        }
        else if(p->data<q->data) p=p->next;
        else q=q->next;
    }
}

void print(){
    if(!head3){
        cout<<"Empty"<<endl;
        return;
    }
    Node* cur=head3;
    while(cur){
        cout<<cur->data;
        if(cur->next) cout<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

int main(){
    int x;
    while(cin>>x && x!=-1){
        insert_back(head1,tail1,x);
    }
    while(cin>>x && x!=-1){
        insert_back(head2,tail2,x);
    }
    intersection();
    print();
    return 0;
}