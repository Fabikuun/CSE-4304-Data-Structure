#include<iostream>
#include<vector>
#include<stack>
#define vi vector<int>
#define pb push_back
#define si stack<int>
using namespace std;

void NGE(vi &arr){
    int n=arr.size();
    vi nge(n);
    si st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[i]>=st.top()){
            st.pop();
        }
        nge[i]=st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout<<nge[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    vi arr;
    while(cin>>n && n!=-1){
        arr.pb(n);
    }
    NGE(arr);
    return 0;
}