#include<iostream>
using namespace std;

int Factorial_using_iteration(int n){
    if(n==0 || n==1) return 1;
    int result=1;
    for(int i=2; i<=n; i++){
        result*=i;
    }
    return result;
}

int Factorial_using_recursion(int n){
    if(n<=1) return 1;
    return n*Factorial_using_recursion(n-1);
}

int main(){
    int n;
    cin>>n;
    if(n>=0){
        cout<<Factorial_using_iteration(n)<<" (using iteration)"<<endl;
        cout<<Factorial_using_recursion(n)<<" (using recursion)"<<endl;
    }
    return 0;
}