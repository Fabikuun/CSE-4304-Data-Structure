#include<iostream>
#include<vector>
using namespace std;
int main(){
    int len, n;
    cin>>len>>n;
    vector<pair<string, int>> dna(n);
    for(int i=0; i<n; i++){
        cin>>dna[i].first;
        dna[i].second=0;
    }
    for(int i=0; i<n; i++){ //alada string er jonne


        for(int j=0; j<len-1; j++){
            for(int k=j+1; k<len; k++){
                if(dna[i].first[j]>dna[i].first[k]){
                    dna[i].second++;
                }
            }
        }
    }
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped=false;
        for(int j=0; j<n-1-i; j++){
            if(dna[j].second>dna[j+1].second){
                swap(dna[j], dna[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    for(int i=0; i<n; i++){
        cout<<dna[i].first<<" "<<dna[i].second<<"\n";
    }
    return 0;
}