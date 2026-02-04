#include<iostream>
#include<vector>
#define pb push_back
using namespace std;

struct node{
    node* bit[2];
};
node* root;
node* createNode(){
    node* n=new node;
    n->bit[0]=NULL;
    n->bit[1]=NULL;
    return n;
}

void insert(int num){
    node* curr=root;
    for(int i=31; i>=0; i--){
        int b=(num>>i) & 1;
        if(curr->bit[b]==NULL){
            curr->bit[b]=createNode();
        }
        curr=curr->bit[b];
    }
}

int getMaxXor(int num){
    node* curr=root;
    int maxXor=0;
    for(int i=31; i>=0; i--){
        int b=(num>>i) & 1;
        if(b==0 && curr->bit[1]!=NULL){
            maxXor+=(1<<i);
            curr=curr->bit[1];
        }
        else if(b==1 && curr->bit[0]!=NULL){
            maxXor+=(1<<i);
            curr=curr->bit[0];
        }
        else{
            curr=curr->bit[b];
        }
    }
    return maxXor;
}

int main(){
    root=createNode();
    vector<int> number;
    int x;
    while(cin>>x && x!=-1){
        number.pb(x);
    }
    for(int i=0; i<number.size(); i++){
        insert(number[i]);
    }
    int maxXor=0;
    for(int i=0; i<number.size(); i++){
        maxXor=max(maxXor, getMaxXor(number[i]));
    }
    cout<<maxXor<<endl;
    return 0;
}