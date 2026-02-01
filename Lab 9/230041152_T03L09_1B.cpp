#include<iostream>
#include<string>
using namespace std;

struct node{
    node* next[26];
    bool endMark;
};
node* root;
node* createnode(){
    node* n= new node();
    n->endMark=false;
    for(int i=0;i<26;i++) n->next[i]=NULL;
    return n;
}

void insert(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr->next[idx]==NULL){
            curr->next[idx]=createnode();
        }
        curr=curr->next[idx];
    }
    curr->endMark=true;
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

void displayTrie(node* curr, string s){
    if(curr->endMark)
        cout<<s<<endl;
    for(int i=0; i<26; i++){
        if(curr->next[i]!=NULL){
            displayTrie(curr->next[i], s+char(i+'a'));
        }
    }
}

int main(){
    root=createnode();
    string line;
    getline(cin, line);
    string word="";
    for(int i=0; i<=line.length(); i++){
        if(i==line.length() || line[i]==' '){
            if(!word.empty()){
                insert(word);
                word="";
            }
        }
        else{
            word+=line[i];
        }
    }
    displayTrie(root, "");
    getline(cin, line);
    word="";
    for(int i=0; i<=line.length(); i++){
        if(i==line.length() || line[i]==' '){
            if(!word.empty()){
                if(search(word)) cout<<"T"<<endl;
                else cout<<"F"<<endl;
                word="";
            }
        }
        else{
            word+=line[i];
        }
    }
    return 0;
}