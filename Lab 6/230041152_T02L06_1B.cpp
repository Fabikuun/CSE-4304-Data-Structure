#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
}Node;

Node* treeRoot=NULL;

Node* createNode(int data){
    Node* n= new Node();
    n->data=data;
    n->height=0;
    n->left=n->right=n->parent=NULL;
    return n;
}

void print_tree(Node* node){
    if(node==NULL) return;
    print_tree(node->left);
    cout<<node->data<<" ";
    print_tree(node->right);
}

void insert(int data){
    Node* n=createNode(data);
    Node* temp=treeRoot;
    Node* target=NULL;
    if(temp==NULL){
        treeRoot=n;
        print_tree(treeRoot);
        cout<<endl;
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
    while(target!=NULL){
        int leftHeight=(target->left) ? target->left->height:-1;
        int rightHeight=(target->right) ? target->right->height:-1;
        target->height=(leftHeight>rightHeight ? leftHeight:rightHeight)+1;
        target=target->parent;
    }
    print_tree(treeRoot);
    cout<<endl;
}

void Search(int key){
    Node* node=treeRoot;
    if(node==NULL){
        cout<<"Not Found"<<endl;
        return;
    }
    while(node!=NULL){
        if(node->data<key) node=node->right;
        else if(node->data>key) node=node->left;
        else if(node->data==key){
            cout<<"Present"<<endl;
            if(node->parent==NULL) cout<<"Parent(null), ";
            else cout<<"Parent("<<node->parent->data<<"), ";
            if(node->left==NULL) cout<<"Left(null), ";
            else cout<<"Left("<<node->left->data<<"), ";
            if(node->right==NULL) cout<<"Right(null)";
            else cout<<"Right("<<node->right->data<<")";
            return;
        }
    }
    cout<<"Not found"<<endl;
}

void Height(int key){
    Node* node = treeRoot;
    while(node!=NULL){
        if(node->data<key) node=node->right;
        else if(node->data>key) node = node->left;
        else{
            cout<<node->height<<endl;
            return;
        }
    }
    cout<<"Not Found"<<endl;
}

void Before_after(int key){
    Node* cur=treeRoot;
    while(cur&&cur->data!=key){
        if(cur->data>key) cur=cur->left;
        else cur=cur->right;
    }
    if(cur==NULL){
        cout<<"Not Found"<<endl;
        return;
    }
    Node* before=NULL;
    Node* after=NULL;
    if(cur->left){
        before=cur->left;
        while(before->right){
            before=before->right;
        }
    }
    else{
        while(cur->parent && cur==cur->parent->left){
            cur=cur->parent;
        }
        before=cur->parent;
    }
    cur=treeRoot;
    while(cur&&cur->data != key){
        if(key<cur->data) cur=cur->left;
        else cur=cur->right;
    }
    if(cur->right){
        after=cur->right;
        while(after->left){
            after=after->left;
        }
    }
    else{
        while(cur->parent && cur==cur->parent->right){
            cur=cur->parent;
        }
        after=cur->parent;
    }
    if(before) cout<<before->data<<" ";
    else cout<<"null ";
    if(after) cout<<after->data<<endl;
    else cout<<"null"<<endl;
}

void Max_min(int key){
    Node* curr=treeRoot;
    while(curr && curr->data!=key){
        if(curr->data>key) curr=curr->left;
        else curr=curr->right;
    }
    if(curr==NULL){
        cout<<"Not Found"<<endl;
        return;
    }
    if(curr->left==NULL && curr->right==NULL){
        cout<<curr->data<<endl;
        return;
    }
    Node* min=curr;
    while(min->left!=NULL){
        min=min->left;
    }
    Node* max=curr;
    while(max->right!=NULL){
        max=max->right;
    }
    cout<<min->data<<" "<<max->data<<endl;
}

int main(){
    int op, key;
    while(cin>>op){
        if(op==-1) break;
        cin >> key;
        if(op==1) insert(key);
        else if(op==3) Search(key);
        else if(op==4) Height(key);
        else if(op==5) Before_after(key);
        else if(op==6) Max_min(key);
    }
    return 0;
}
