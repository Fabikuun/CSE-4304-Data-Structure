#include<iostream>
#include<string>
#include<unordered_map>
#include<cctype>
#define umap unordered_map
using namespace std;

int main(){
    umap<string, int> count;
    string sentence;
    getline(cin, sentence);
    string word="";
    for(int i=0; i<=sentence.length(); i++){
        if(i<sentence.length() && isalpha(sentence[i])){
            word+=tolower(sentence[i]);
        }
        else{
            if(!word.empty()){
                count[word]++;
                word="";
            }
        }
    }
    for(auto pair : count){
        if(pair.second>1){
            cout<<pair.first<<" "<<pair.second<<endl;
        }
    }
    return 0;
}