#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define pb push_back
using namespace std;

void Checker(vector<string> htmlCode, int numLine){
    stack<string> s;
    string data,tag;
    for(int i=0; i<numLine; i++){
        int pos=0;
        data=htmlCode[i];
        while(pos<data.length()){
            tag.erase();
            if(data[pos]=='<'){
                while(data[pos]!='>'){
                    tag.pb(data[pos]);
                    pos++;
                }
                tag.pb('>');
                if(tag[1]=='/'){
                    string opentag="<"+tag.substr(2);
                    if(s.empty()){
                    cout<<"Error at line "<<i+1;
                    return;
                    }
                    if(s.top()==opentag) s.pop();
                    else{
                        cout<<"Error at line "<<i+1;
                        return;
                    }
                }
                else s.push(tag);
            }
            pos++;
        }
    }
    if(s.empty()) cout<<"No error";
    else cout<<"Error at line "<<numLine;
}

int main(){
    vector<string> htmlCode;
    string temp;
    int linenum, x;
    cin>>linenum;
    cin.ignore();
    for (int i=0; i<linenum; i++){
        getline(cin, temp);
        htmlCode.pb(temp);
    }
    cin>>x;
    Checker(htmlCode, linenum);
    return 0;
}
