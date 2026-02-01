#include<iostream>
#include<string>
using namespace std;

struct node{
    node* next[26];
    bool endMark;
    int count;
};
node* root;
node* createnode(){
    node* n= new node();
    n->endMark=false;
    n->count=0;
    for(int i=0;i<26;i++) n->next[i]=NULL;
    return n;
}

bool search(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr->next[idx]==NULL){
            return false;
        }
        curr=curr->next[idx];
    }
    return curr->endMark;
}

void insert(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr->next[idx]==NULL){
            curr->next[idx]=createnode();
        }
        curr=curr->next[idx];
        curr->count++;
    }
    curr->endMark=true;
}

string toLower(string s){
    string result="";
    for(char c:s){
        result+=tolower(c);
    }
    return result;
}

int prefixCount(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr->next[idx]==NULL){
            return 0;
        }
        curr=curr->next[idx];
    }
    return curr->count;
}

int main(){
    root=createnode();
    int N,Q;
    cin>>N>>Q;
    for(int i=0; i<N; i++){
        string word;
        cin>>word;
        word=toLower(word);
        if(!search(word)){
            insert(word);
        }
    }
    for(int i=0; i<Q; i++){
        string prefix;
        cin>>prefix;
        prefix=toLower(prefix);
        cout<<prefixCount(prefix)<<endl;
    }
    return 0;
}