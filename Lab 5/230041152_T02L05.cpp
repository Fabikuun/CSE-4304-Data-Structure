#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node* prev;
}Node;

Node* head=NULL;
Node* tail=NULL;

void print(){
    if(!head){
        cout<<"Head=Null, Tail=Null, "<<endl;
        cout<<"Head2Tail: Empty"<<endl;
        cout<<"Tail2Head: Empty"<<endl;
        return;
    }

    cout<<"Head="<<head->data<<", Tail="<<tail->data<<", "<<endl;

    cout<<"Head2Tail: ";
    Node* cur=head;
    while(cur){
        cout<<cur->data;
        if(cur->next) cout<<" ";
        cur=cur->next;
    }
    cout<<endl;

    cout<<"Tail2Head: ";
    cur=tail;
    while(cur){
        cout<<cur->data;
        if(cur->prev) cout<<" ";
        cur=cur->prev;
    }
    cout<<endl;
}

void insert_front(int key){ //1
    Node* n=new Node{key, head, NULL};
    if(head) head->prev=n;
    head=n;
    if(!tail) tail=n;
}

void insert_back(int key){ //2
    Node* n=new Node{key, NULL, tail};
    if(!tail){
        head=tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}

void insert_after_node(int key, int v){ //3
    Node* n=head;
    while(n && n->data!=v){
        n=n->next;
    }
    if(!n){
        cout<<"Value not found"<<endl;
        return;
    }
    Node* curr=new Node{key, n->next, n};
    if(n->next) n->next->prev=curr;
    n->next=curr;
    if(curr->next==NULL) tail=curr;
}

void update_node(int key, int v){ //4
    Node* n=head;
    while(n && n->data!=v){
        n=n->next;
    }
    if(!n){
        cout<<"Value not found"<<endl;
        return;
    }
    n->data=key;
}

void remove_head(){ //5
    if(!head){
        cout<<"Underflow"<<endl;
        return;
    }
    Node* n=head;
    head=head->next;
    if(head) head->prev=NULL;
    else tail=NULL;
    delete n;
}

void remove_element(int key){ //6
    if(!head){
        cout<<"Value not found"<<endl;
        return;
    }
    Node* n=head;
    while(n && n->data!=key){
        n=n->next;
    }
    if(!n){
        cout<<"Value not found"<<endl;
        return;
    }
    if(n==head){
        remove_head();
        return;
    }
    if(n==tail){
        tail=tail->prev;
        tail->next=NULL;
        delete n;
        return;
    }
    n->prev->next=n->next;
    n->next->prev=n->prev;
    delete n;
}

void remove_end(){ //7
    if(!tail){
        cout<<"Underflow"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head=tail=NULL;
        return;
    }
    Node* n=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete n;
}

int main(){
    int op;
    while(cin>>op){
        if(op==1){
            int v;
            cin>>v;
            insert_front(v);
            print();
        }
        else if(op==2){
            int v;
            cin>>v;
            insert_back(v);
            print();
        }
        else if(op==3){
            int key,v;
            cin>>key>>v;
            insert_after_node(key,v);
            print();
        }
        else if(op==4){
            int key,v;
            cin>>key>>v;
            update_node(key,v);
            print();
        }
        else if(op==5){
            remove_head();
            print();
        }
        else if(op==6){
            int key;
            cin>>key;
            remove_element(key);
            print();
        }
        else if(op==7){
            remove_end();
            print();
        }
        else if(op==8){
            cout<<"Exit"<<endl;
            break;
        }
    }
    return 0;
}