#include<iostream>
using namespace std;
int main(){
    int n,r;
    cin>>n>>r;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<r; i++){
        int power, sum=0, count=0;
        cin>>power;
        for(int j=0; j<n; j++){
            if(a[j]<=power){
                sum+=a[j];
                count++;
            }
        }
        cout<<count<<" "<<sum<<"\n";
    }
    return 0;
}