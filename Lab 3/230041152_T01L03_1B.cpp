#include<iostream>
using namespace std;

int *arr;
int frontIndex=0, rearIndex=-1, capacity=0, count=0;

bool isEmpty(){  //3
    return count==0;
}
bool isFull(){  //4
    return count==capacity;
}
int size(){ //5
    return count;
}
int front(){  //6
    if(isEmpty()){
        return -1;
    }
    return arr[frontIndex];
}
void display(){
    if(isEmpty()){
        cout<<endl;
        return;
    }
    int idx=frontIndex;
    for(int i=0; i<count; i++){
        cout<<arr[idx];
        if(i<count-1) cout<<" ";
        idx++;
        idx%=capacity;
    }
    cout<<endl;
}
void enqueue(int data){ //1
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }
    rearIndex++;
    rearIndex%=capacity;
    arr[rearIndex]=data;
    count++;
    display();
}
void dequeue(){  //2
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return;
    }
    frontIndex++;
    frontIndex%=capacity;
    count--;
    display();
}

int main(){
    int t;
    cin>>t;
    capacity=t;
    arr=new int[capacity];
    int idx;
    while(cin>>idx){
        switch(idx){
            case 1:{
                int data;
                cin>>data;
                cout<<"Enqueue: ";
                enqueue(data);
                break;
            }
            case 2:{
                cout<<"Dequeue: ";
                dequeue();
                break;
            }
            case 3:{
                cout<<"IsEmpty: ";
                if(isEmpty()) cout<<"True"<<endl;
                else cout<<"False"<<endl;
                break;
            }
            case 4:{
                cout<<"IsFull: ";
                if(isFull()) cout<<"True"<<endl;
                else cout<<"False"<<endl;
                break;
            }
            case 5:{
                cout<<"Size: ";
                cout<<size()<<endl;
                break;
            }
            case 6:{
                cout<<"Front: ";
                cout<<front()<<endl;
                break;
            }
        }
        if(idx==-1){
            cout<<"Exit"<<endl;
            break;
        }
    }
    delete[] arr;
    return 0;
}