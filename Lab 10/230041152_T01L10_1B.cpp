#include<iostream>
#include<vector>
#define pb push_back
#define vi vector<int>
using namespace std;

void initialize(vi &v, int N){      //option 1
    for(int i=0; i<N; i++){
        v[i]=i;
    }
}
int Find(vi &v, int target){        //option 2
    if(v[target]==target){
        return target;
    }
    return Find(v, v[target]);
}
void Union(vi &v, int a, int b){   //option 3
    int rootA=Find(v, a);
    int rootB=Find(v, b);
    if(rootA!=rootB){
        v[rootB]=rootA;
    }
}
void print(vi &v, int N){
    for(int i=0; i<N; i++){
        cout<<v[i];
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;
}
int main(){
    int N;
    cin>>N;
    vi parentArray(N);
    int option;
    while(cin>>option && option!=-1){
        if(option==1){
            initialize(parentArray, N);
            print(parentArray, N);
        }
        else if(option==2){
            int target;
            cin>>target;
            cout<<Find(parentArray, target)<<endl;
        }
        else if(option==3){
            int a, b;
            cin>>a>>b;
            Union(parentArray, a, b);
            print(parentArray, N);
        }
    }
    return 0;
}