#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
int main(){
    vector<int> num1, num2, result;
    int freq[1001]={0};
    int n;
    while(cin>>n && n!= -1){
        num1.pb(n);
    }
    while(cin>>n && n!= -1){
        num2.pb(n);
    }
    for(int i=0; i<num1.size(); i++){
        freq[num1[i]]++;
    }
    for(int i=0; i<num2.size(); i++){
        if(freq[num2[i]]>0){
            result.pb(num2[i]);
            freq[num2[i]]--;  //important 
        }
    }
    for(int i=0; i<result.size(); i++){
        if(i>0) cout<<" ";
        cout<<result[i];
    }
    cout<<endl;
    return 0;
}