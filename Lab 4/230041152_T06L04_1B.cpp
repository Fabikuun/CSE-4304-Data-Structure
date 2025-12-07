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

int Heap_Maximum(int heap[]){
    return heap[1];
}

int Heap_extract_max(int heap[]){
    if(n<1) return -1;
    int max=heap[1];
    heap[1]=heap[n];
    n--;
    heapify(1);
    return max;
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

void Heap_increase_key(int i, int key, int heap[]){
    if(key<heap[i]) return;
    heap[i]+=key;
    while(i>1 && heap[i/2]<heap[i]){
        swap(heap[i],heap[i/2]);
        i=i/2;
    }
}

void Heap_decrease_key(int i, int key, int heap[]){
    if(key>heap[i]) return;
    heap[i]-=key;
    heapify(i);
}

void printHeap(){
    for(int i=1; i<=n; i++){
        cout<<heap[i]<<" ";
    }
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
    printHeap();
    while(true){
        int choice;
        cin>>choice;
        if(choice==-1){
            return 0;
        }
        else if(choice==1){
            cout<<Heap_Maximum(heap)<<endl;
            build_max_heap();
            printHeap();
            cout<<endl;
        }
        else if(choice==2){
            int max=Heap_extract_max(heap);
            if(max==-1){
                cout<<"Heap underflow"<<endl;
            }
            else{
                cout<<max<<endl;
                build_max_heap();
                printHeap();
                cout<<endl;
            }
        }
        else if(choice==3){
            int value;
            cin>>value;
            Max_heap_insert(value, heap);
            build_max_heap();
            printHeap();
            cout<<endl;
        }
        else if(choice==4){
            int i, key;
            cin>>i>>key;
            Heap_decrease_key(i, key, heap);
            build_max_heap();
            printHeap();
            cout<<endl;
        }
        else if(choice==5){
            int i, key;
            cin>>i>>key;
            Heap_increase_key(i, key, heap);
            build_max_heap();
            printHeap();
            cout<<endl;
        }
    }
    return 0;
}
