#include<iostream>
#define ll long long
using namespace std;
int main(){
    int freq[10]={0}, idx[10];
    for(int i=0; ;i++){
        int x;
        cin>>x;
        if(x<=0) break;
        freq[x]++;
        idx[x]=x;
    }
    bool swapped;
    for(int i=0; i<9; i++){
        swapped=false;
        for(int j=0; j<9-i; j++){
            if(freq[j]>freq[j+1]){
                swap(idx[j], idx[j+1]);
                swap(freq[j], freq[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    for(int i=9; i>0; i--){
        if(freq[i]!=0){
            cout<<idx[i]<<" occurs "<<freq[i]<<" times\n";
        }
    }
    return 0;
}