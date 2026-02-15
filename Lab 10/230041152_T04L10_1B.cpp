#include<iostream>
#include<vector>
#include<queue>
#define pb push_back
#define vi vector<int>
#define qi queue<int>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<vi> adjacent(N);
    vi indegree(N,0), tpoSort;
    qi q;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        adjacent[a].pb(b);
        indegree[b]++;
    }
    for(int i=0; i<N; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        tpoSort.pb(curr);
        for(int i=0; i<adjacent[curr].size(); i++){
            int next=adjacent[curr][i];
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
    if(tpoSort.size()!=N){
        cout<<"[ ]"<<endl;
    }
    else{
        for(int i=0; i<tpoSort.size(); i++){
            cout<<tpoSort[i];
            if(i!=tpoSort.size()-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}