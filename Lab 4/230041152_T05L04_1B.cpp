#include<iostream>
int heap[100000];
int n;
using namespace std;

void heapify(int i){
    int left=2*i, right=2*i+1, smallest=i;
    if(left<=n && heap[left]<heap[smallest])
        smallest=left;
    if(right<=n && heap[right]<heap[smallest])
        smallest=right;
    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        heapify(smallest);
    }
}

void build_min_heap(){
    for(int i=(n/2); i>=1; i--){
        heapify(i);
    }
}

void heap_sort(){
    build_min_heap();
    int heapSize=n;
    for(int i=n; i>=2; i--){
        swap(heap[1], heap[i]);
        n--;
        heapify(1);
    }
    n=heapSize;
    for(int i=1; i<=n/2; i++){
        swap(heap[i], heap[heapSize-i+1]);
    }
}

int main(){
    while(true){
        int x;
        cin>>x;
        if(x==-1) break;
        heap[++n]=x;
    }
    cout<<"Min Heap: ";
    build_min_heap();
    for(int i=1; i<=n; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    cout<<"Sorted: ";
    heap_sort();
    for(int i=1; i<=n; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    return 0;
}