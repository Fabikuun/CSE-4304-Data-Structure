#include<iostream>
#include<vector>
#include<unordered_map>
#define pb push_back
using namespace std;
int main(){
    unordered_map<int,int> freq;
    vector<int> numbers;
    int x;
    while(cin>>x && x!=-1){
        numbers.pb(x);
        freq[x]++;
    }
    int target;
    cin>>target;
    bool found=false;
    for(int i=0; i<numbers.size(); i++){
        int a=numbers[i];
        int b=target-a;
        if(freq[a]>0 && freq[b]>0){
            if(a==b && freq[a]<2) continue;
            freq[a]--;
            freq[b]--;
            cout<<"("<<a<<","<<b<<")";
            found=true;
            cout<<", ";
        }
    }
    if(!found){
        cout<<"No pairs found";
    }
    cout<<endl;
    return 0;
}