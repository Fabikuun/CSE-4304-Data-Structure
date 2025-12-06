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
int Heap_Minimum(int heap[]){
    return heap[1];
}
int Heap_Extract_Min(int heap[]){
    if(n<1) return -1;
    int min=heap[1];
    heap[1]=heap[n];
    n--;
    heapify(1);
    return min;
}
void Min_Heap_Insert(int value, int heap[]){
    n++;
    heap[n]=value;
    int i=n;
    while(i>1 && heap[i/2]>heap[i]){
        swap(heap[i],heap[i/2]);
        i=i/2;
    }
}
void Heap_Decrease_Key(int i, int key, int heap[]){
    if(key>heap[i]) return;
    heap[i]-=key;
    while(i>1 && heap[i/2]>heap[i]){
        swap(heap[i],heap[i/2]);
        i=i/2;
    }
}
void Heap_Increase_Key(int i, int key, int heap[]){
    if(key<heap[i]) return;
    heap[i]+=key;
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
    cout<<"Min Heap: ";
    build_min_heap();
    printHeap();
    while(true){
        int choice;
        cin>>choice;
        if(choice==-1){
            return 0;
        }
        else if(choice==1){
            cout<<Heap_Minimum(heap)<<endl;
            build_min_heap();
            printHeap();
            cout<<endl;
        }
        else if(choice==2){
            int min=Heap_Extract_Min(heap);
            if(min==-1){
                cout<<"Heap underflow"<<endl;
            }
            else{
                cout<<min<<endl;
                build_min_heap();
                printHeap();
                cout<<endl;
            }
        }
        else if(choice==3){
            int value;
            cin>>value;
            Min_Heap_Insert(value, heap);
            build_min_heap();
            printHeap();
            cout<<endl;
        }
        else if(choice==4){
            int i, key;
            cin>>i>>key;
            Heap_Decrease_Key(i, key, heap);
            build_min_heap();
            printHeap();
            cout<<endl;
        }
        else if(choice==5){
            int i, key;
            cin>>i>>key;
            Heap_Increase_Key(i, key, heap);
            build_min_heap();
            printHeap();
            cout<<endl;
        }
    }
    return 0;
}