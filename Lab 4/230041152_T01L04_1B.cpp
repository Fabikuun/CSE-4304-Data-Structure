#include<iostream>
int heap[100000];
int n;
using namespace std;

void heapify(int i){
    int left=2*i, right=2*i+1, largest=i;
    if(left<=n && heap[left]>heap[largest])
        largest=left;
    if(right<=n && heap[right]>heap[largest])
        largest=right;
    if(largest!=i){
        swap(heap[i],heap[largest]);
        heapify(largest);
    }
}

void build_max_heap(){
    for(int i=(n/2); i>=1; i--){
        heapify(i);
    }
}

void heap_sort(){
    build_max_heap();
    int heapSize=n;
    for(int i=n; i>=2; i--){
        swap(heap[1], heap[i]);
        n--;
        heapify(1);
    }
    n=heapSize;
}

int main(){
    while(true){
        int x;
        cin>>x;
        if(x==-1) break;
        heap[++n]=x;
    }
    cout<<"Max Heap: ";
    build_max_heap();
    for(int i=1; i<=n; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    cout<<"Sorted: ";
    heap_sort();
    for(int i=n; i>=1; i--){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    return 0;
}