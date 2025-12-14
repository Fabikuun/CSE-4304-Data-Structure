#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* head=NULL;
Node* tail=NULL;

void insert_front(int key){ //1
    Node* n=new Node{key, head};
    head=n;
    if(!tail) tail=n;
}

void insert_back(int key){ //2
    Node* n=new Node{key, NULL};
    if(!tail){
        head=tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}

void insert_after_node(int key, int v){ //3
    Node* n = head;
    while(n->next!=NULL && n->data!=v){
        n=n->next;
    }
    if(!n){
        cout<<"Value not found"<<endl;
        return;
    }
    Node* curr=new Node;
    curr->data=key;
    curr->next=n->next;
    n->next=curr;
    if(curr->next==NULL) tail=curr;
}

void update_node(int key, int v){  //4
    Node *n=head;
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
    if(head==NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    Node*n=head;
    head=head->next;
    free(n);
    if(!head) tail=NULL;
}

void remove_element(int key){ //6
    if(!head){
        cout<<"Value not found"<<endl;
        return;
    }
    if(head->data==key){
        Node* t=head;
        head=head->next;
        free(t);
        if(!head) tail=NULL;
        return;
    }
    Node* n=head;
    while(n->next && n->next->data!=key){
        n=n->next;
    }
    if(!n->next){
        cout<<"Value not found"<<endl;
        return;
    }
    Node* t=n->next;
    n->next=t->next;
    if(t==tail) tail=n;
    free(t);
}

void remove_end(){ //7
    if(!head){
        cout<<"Underflow"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head=tail=NULL;
        return;
    }
    Node* n=head;
    while(n->next!=tail){
        n=n->next;
    }
    free(tail);
    tail=n;
    tail->next=NULL;
}

void print(){
    if(!head){
        cout<<"Head=Null, Tail=Null, Empty"<<endl;
        return;
    }
    cout<<"Head="<<head->data<<", Tail="<<tail->data<<", ";
    Node* cur = head;
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
            break;
        }
    }
    return 0;
}