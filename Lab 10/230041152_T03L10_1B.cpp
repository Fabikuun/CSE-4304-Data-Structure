#include<iostream>
#include<vector>
#define pb push_back
#define vi vector<int>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector<vi> adjList(V+1);
    vector<vi> adjMatrix(V+1);
    for(int i=0; i<=V; i++){
        adjMatrix[i]=vi(V+1,0);
    }
    int u,v;
    for(int i=0; i<E; i++){
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }
    cout<<"Adjacency List:"<<endl;
    for(int i=1; i<=V; i++){
        cout<<i<<": ";
        for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j];
            if(j!=adjList[i].size()-1) cout<<" ";
        }
        cout<<endl;
    }
    cout<<"Adjacency Matrix:"<<endl;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            cout<<adjMatrix[i][j];
            if(j!=V) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}