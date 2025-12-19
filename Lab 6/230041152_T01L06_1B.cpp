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
    Node* n= new Node();
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

void inorder(Node* node){ //1
    if(node==NULL) return;
    inorder(node->left);
    cout<<node->data;
    if(node->parent==NULL) cout<<"(null) ";
    else cout<<"("<<node->parent->data<<") ";
    inorder(node->right);
}

void preorder(Node* node){ //2
    if(node==NULL) return;
    cout<<node->data;
    if(node->parent==NULL) cout<<"(null) ";
    else cout<<"("<<node->parent->data<<") ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node){ //3
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data;
    if(node->parent==NULL) cout<<"(null) ";
    else cout<<"("<<node->parent->data<<") ";
}

void lvlOrder(Node* root){ //4
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    int lvl=1;
    while(!q.empty()){
        int size=q.size();
        cout<<"Level "<<lvl<<": ";
        while(size--){
            Node* cur=q.front();
            q.pop();
            cout<<cur->data;
            if(cur->parent==NULL) cout<<"(null) ";
            else cout<<"("<<cur->parent->data<<") ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout<<endl;
        lvl++;
    }
}

int main(){
    int N;
    cin>>N;
    while(N--){
        int x;
        cin>>x;
        insert(x);
    }
    int op;
    while(cin>>op && op!=-1){
        if(op==1){
            cout<<"Inorder:"<<endl;
            inorder(treeRoot);
            cout<<endl;
        }
        else if(op==2){
            cout<<"Preorder:"<<endl;
            preorder(treeRoot);
            cout<<endl;
        }
        else if(op==3){
            cout<<"Postorder:"<<endl;
            postorder(treeRoot);
            cout<<endl;
        }
        else if(op==4){
            lvlOrder(treeRoot);
            cout<<endl;
        }
    }
    return 0;
}