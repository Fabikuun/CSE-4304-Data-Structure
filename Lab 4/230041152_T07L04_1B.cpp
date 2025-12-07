#include<iostream>
#include<queue>
#define ll long long
using namespace std;
int heap[1000];
int n=0;

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

void Max_heap_insert(int value, int heap[]){
    n++;
    heap[n]=value;
    int i=n;
    while(i>1 && heap[i/2]<heap[i]){
        swap(heap[i],heap[i/2]);
        i=i/2;
    }
}

int Heap_extract_max(int heap[]){
    if(n<1) return -1;
    int max=heap[1];
    heap[1]=heap[n];
    n--;
    heapify(1);
    return max;
}

int main(){
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        int x;
        cin>>x;
        Max_heap_insert(x, heap);
        if(n>=3){
            int max1=Heap_extract_max(heap);
            int max2=Heap_extract_max(heap);
            int max3=Heap_extract_max(heap);
            ll product=(ll)max1*max2*max3;
            cout<<product<<endl;
            Max_heap_insert(max1, heap);
            Max_heap_insert(max2, heap);
            Max_heap_insert(max3, heap);
        }
        else cout<<-1<<endl;
    }
    return 0;
}