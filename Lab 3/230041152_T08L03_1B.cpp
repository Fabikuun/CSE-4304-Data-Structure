#include<iostream>
#include<string>
#include<queue>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;

int main(){
    int N;
    cin>>N;
    deque<int> dq;
    for(int i=0; i<N; i++){
        int x;
        cin>>x;
        dq.pb(x);
    }
    string p1, p2;
    cin>>p1;
    if(p1=="Daiyan") p2="Ishraq";
    else p2="Daiyan";
    while(dq.size()>1){
        if(p1=="Daiyan"){
            dq.pb(dq.front());
            dq.ppf();
            dq.ppf();
            cout<<"Daiyan ";
            for(int i=0; i<dq.size(); i++){
                if(i) cout<<" ";
                cout<<dq[i];
            }
            cout<<endl;
        }
        else{
            dq.pb(dq.front());
            dq.ppf();
            dq.pb(dq.front());
            dq.ppf();
            dq.ppf();
            cout<<"Ishraq ";
            for(int i=0; i<dq.size(); i++){
                if(i) cout<<" ";
                cout<<dq[i];
            }
            cout<<endl;
        }
        swap(p1, p2);
    }
    return 0;
}