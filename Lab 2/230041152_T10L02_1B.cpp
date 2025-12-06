#include<iostream>
#include<stack>
using namespace std;

bool canSort(int arr[], int n) {
    stack<int>side;
    int next=1; 
    for (int i=0; i<n; i++) {
        int truck = arr[i];
        while(!side.empty() && side.top()==next){
            side.pop();
            next++;
        }
        if(truck==next) next++;
        else side.push(truck);
    }
    while(!side.empty() && side.top()==next) {
        side.pop();
        next++;
    }
    return(next==n+1);
}

int main() {
    while(true) {
        int n;
        cin>>n;
        if(n==0) break;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        if (canSort(arr, n)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
