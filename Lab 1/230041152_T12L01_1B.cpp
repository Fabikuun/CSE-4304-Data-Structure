#include<iostream>
using namespace std;
int main(){
    int houses[1001], n, size=0;
    while(cin>>n && n!=-1){
        houses[size]=n;
        size++;
    }
    int prev1=0, prev2=0;
    for(int i=0; i<size; i++){
        int temp = prev1;
        prev1 = max(prev2+houses[i], prev1);
        prev2 = temp;
    }
    cout<<prev1<<endl;
    return 0;
}