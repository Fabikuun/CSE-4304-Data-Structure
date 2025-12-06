#include<iostream>
using namespace std;
int main(){
    int len, idx=0;
    string str;
    char song[1000];
    cin>>len>>str;
    bool firstWord=true;
    for(int i=0; i<len; i++){
        bool found=false;
        if(str[i]=='d' && str[i+1]=='u' && str[i+2]=='b'){
            if(!firstWord){
                song[idx]=' ';
                idx++;
            }
            i+=2;
        }
        else{
            song[idx]=str[i];
            idx++;
            firstWord=false;
        }
    }
    song[idx]='\0';
    cout<<song<<endl;
    return 0;
}