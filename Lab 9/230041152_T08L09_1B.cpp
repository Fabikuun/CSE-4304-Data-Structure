#include<iostream>
#include<string>
#include<vector>
#define pb push_back
using namespace std;

bool abbreviates(string word, string abbr){
    return word==abbr;
}

string toUppercase(string s){
    string res="";
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z') res+=s[i];
    }
    return res;
}

int main(){
    vector<string> words;
    string str;
    while(cin>>str && str!="-1"){
        words.pb(str);
    }
    string abbr;
    cin>>abbr;
    for(int i=0; i<words.size(); i++){
        string capsLocked=toUppercase(words[i]);
        (abbreviates(capsLocked,abbr)) ? cout<<"T": cout<<"F";
    }
    return 0;
}