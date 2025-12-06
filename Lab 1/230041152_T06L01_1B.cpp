#include<iostream>
using namespace std;

long long iterativeFibonacci(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    long long prev2=0, prev1=1, result=0;
    for(int i=3; i<=n; i++){
        result=prev1+prev2;
        prev2=prev1;
        prev1=result;
    }
    return result;
}

long long recursiveFibonacci(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return recursiveFibonacci(n-1)+recursiveFibonacci(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<iterativeFibonacci(n)<<" (using iteration)"<<endl;
    cout<<recursiveFibonacci(n)<<" (using recursion)"<<endl;
    return 0;
}