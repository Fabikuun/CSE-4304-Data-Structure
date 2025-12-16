#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node* prev;
}Node;

Node* head=NULL;
Node* tail=NULL;

void insert_back(int key){
    Node* n=new Node{key, NULL};
    if(!tail){
        head=tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}

void remove_duplicates(){
    if(!head) return;
    Node* cur=head;
    while(cur && cur->next){
        if(cur->data==cur->next->data){
            Node* temp=cur->next;
            cur->next=temp->next;
            if(temp==tail) tail=cur;
            delete temp;
        }
        else{
            cur=cur->next;
        }
    }
}

void print(){
    Node* cur=head;
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
        insert_back(x);
    }
    remove_duplicates();
    print();
    return 0;
}