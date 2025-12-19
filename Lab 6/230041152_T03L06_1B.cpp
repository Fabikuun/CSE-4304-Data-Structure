#include<iostream>
#include<queue>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
}Node;

Node* treeRoot=NULL;

Node* createNode(int data){
    Node* n=new Node();
    n->data=data;
    n->left=n->right=n->parent=NULL;
    return n;
}

void insert(int data){
    Node* n=createNode(data);
    Node* temp=treeRoot;
    Node* target=NULL;
    if(temp==NULL){
        treeRoot=n;
        return;
    }
    while(temp!=NULL){
        target=temp;
        if(data<temp->data) temp=temp->left;
        else temp=temp->right;
    }
    n->parent=target;
    if(data<target->data) target->left=n;
    else target->right=n;
}

Node* LCA(Node* root,int u,int v){
    while(root!=NULL){
        if(u<root->data && v<root->data) root=root->left;
        else if(u>root->data && v>root->data) root=root->right;
        else return root;
    }
    return NULL;
}

int main(){
    int N;
    cin>>N;
    while(N--){
        int x;
        cin>>x;
        insert(x);
    }
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        Node* ans=LCA(treeRoot,u,v);
        if(ans) cout<<ans->data<<endl;
    }
    return 0;
}