#include<iostream>
using namespace std;
int main(){
    int position[1000];
    double result[1000];
    int pos, n=0;
    while(cin>>pos && pos!=-1){
        position[n]=pos;
        n++;
    }
    for(int i=0; i<n; i++){
        cin>>result[position[i]-1];
    }
    for(int i=0; i<n; i++){
        if(i<n-1){
            cout<<result[i]<<" ";
        }
        else{
            cout<<result[i]<<endl;
        }
    }
    return 0;
}