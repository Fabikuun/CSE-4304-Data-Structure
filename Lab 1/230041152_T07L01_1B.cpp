#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    string str;
    cin>>str;
    int len=str.length();
    int num[100], n=0;
    for(int i=0; i<len; i++){
        if(str[i]>='0' && str[i]<='9'){
            num[n]=str[i]-'0';
            n++;
        }
    }
    bubblesort(num, n);
    for(int i=0; i<n; i++){
        cout<<num[i];
        if(i<n-1) cout<<"+";
    }
    cout<<endl;
    return 0;
}