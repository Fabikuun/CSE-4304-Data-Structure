#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
struct node{
    node* next[26];
    bool endMark;
    vector<string> suggestions;

};
node* root;

node* createNode(){
    node* n=new node;
    n->endMark=false;
    for(int i=0; i<26; i++) n->next[i]=NULL;
    return n;
}

void insert(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr->next[idx]==NULL){
            curr->next[idx]=createNode();
        }
        curr=curr->next[idx];
        if(curr->suggestions.size()<3){
            curr->suggestions.pb(s);
        }
    }
    curr->endMark=true;
}

bool search(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr->next[idx]==NULL) return false;
        curr=curr->next[idx];
    }
    return curr->endMark;
}

void searchSuggestions(string s){
    node* curr=root;
    for(int i=0; i<s.length(); i++){
        int idx=s[i]-'a';
        if(curr==NULL){
            cout<<"NULL"<<endl;
            continue;
        }
        if(curr->next[idx]==NULL){
            cout<<"NULL"<<endl;
            curr=NULL;
            continue;
        }
        curr=curr->next[idx];
        if(curr->suggestions.size()==0){
            cout<<"NULL"<<endl;
        }
        else{
            for(string s: curr->suggestions){
                cout<<s<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    root=createNode();
    vector<string> words;
    string str;
    while(cin>>str && str!="-1"){
        words.pb(str);
    }
    sort(words.begin(), words.end());
    for(string w: words){
        insert(w);
    }
    string searchStr;
    cin>>searchStr;
    searchSuggestions(searchStr);
    return 0;
}