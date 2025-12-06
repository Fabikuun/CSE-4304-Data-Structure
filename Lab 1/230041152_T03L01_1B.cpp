#include<iostream>
using namespace std;

int arrsize=0;

int Iterative_binary_search(int x, int array[]){
    int left=0;
    int right=arrsize-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(array[mid]==x){
            return mid;
        }
        else if(array[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

int Recursive_binary_search_finder(int x, int array[], int left, int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(array[mid]==x){
        return mid;
    }
    else if(array[mid]<x){
        return Recursive_binary_search_finder(x, array, mid+1, right);
    }
    else{
        return Recursive_binary_search_finder(x, array, left, mid-1);
    }
}
int Recursive_binary_search(int x, int array[]){
    return Recursive_binary_search_finder(x, array, 0, arrsize-1);
}

int main(){
    int arr[100], n, x;
    while(1){
        cin>>n;
        if(n<0) break;
        arr[arrsize]=n;
        arrsize++;
    }
    cin>>x;
    cout<<Iterative_binary_search(x, arr)<<" (using iteration)"<<endl;
    cout<<Recursive_binary_search(x, arr)<<" (using recursion)"<<endl;
    return 0;
}