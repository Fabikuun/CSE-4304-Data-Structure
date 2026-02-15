#include<iostream>
#include<vector>
#define pb push_back
#define vi vector<int>
using namespace std;

void initialize(vi &v,vi &rankArr, int N){
    for(int i=0; i<N; i++){
        v[i]=i;
        rankArr[i]=0;
    }
}
int Find(vi &v, int target){
    cout<<"f("<<target<<") ";
    if(v[target]==target) return target;
    v[target]=Find(v, v[target]);
    return v[target];
}
void Union(vi &v, vi &rankArr, int a, int b){
    int rootA=Find(v, a);
    cout<<endl;
    int rootB=Find(v, b);
    cout<<endl;
    if(rootA!=rootB){
        if(rankArr[rootA]<=rankArr[rootB]){
            v[rootA]=rootB;
            if(rankArr[rootA]==rankArr[rootB]){
                rankArr[rootB]++;
            }
        }
        else{
            v[rootB]=rootA;
        }
    }
}
void display(vi &v, vi &rankArr, int N){
    for(int i=0; i<N; i++){
        cout<<v[i]<<"("<<rankArr[i]<<")";
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    vi parentArray(N), rankArray(N);
    int option;
    while(cin>>option && option!=-1){
        if(option==1){
            initialize(parentArray, rankArray, N);
            display(parentArray, rankArray, N);
        }
        else if(option==2){
            int target;
            cin>>target;
            int ans=Find(parentArray, target);
            cout<<endl;
            cout<<ans<<endl;
        }
        else if(option==3){
            int a, b;
            cin>>a>>b;
            Union(parentArray, rankArray, a, b);
            display(parentArray, rankArray, N);
        }
        else if(option==4){
            display(parentArray, rankArray, N);
        }
    }
    return 0;
}