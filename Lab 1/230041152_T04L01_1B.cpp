#include<iostream>
#include<vector>
#define ll long long
#define vi vector<int>
#define pb push_back
using namespace std;
int main(){
    vi a;
    vector<pair<int,int>> worker;
    for(int i=0; ;i++){
        int x;
        cin>>x;
        if(x==0) break;
        a.pb(x);
    }
    int n;
    cin>>n;
    for(int i=0; i<a.size()-1; i++){
        for(int j=i+1; j<a.size(); j++){
            if(a[i]+a[j]==n){
                worker.pb({i+1,j+1});
            }
        }
    }
    int pair=worker.size();
    if(pair==0){
        cout<<"No pair found!\n";
        return 0;
    }else{
        cout<<pair<<" pairs:\n";
        for(auto p:worker){
            cout<<"(worker-"<<p.first<<", worker-"<<p.second<<")\n";
        }
    }
    return 0;
}