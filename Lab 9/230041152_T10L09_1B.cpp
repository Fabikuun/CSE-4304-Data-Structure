#include<iostream>
#include<string>
#include<unordered_map>
#define umap unordered_map
using namespace std;
int main(){
    umap<string,int> count;
    string morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int t;
    cin>>t;
    while(t--){
        string word;
        cin>>word;
        string morseCode="";
        for(char c:word){
            morseCode+=morse[c-'a'];
        }
        count[morseCode]++;
    }
    cout<<count.size()<<endl;
    for(auto pair:count){
        cout<<pair.first<<endl;
    }
    return 0;
}