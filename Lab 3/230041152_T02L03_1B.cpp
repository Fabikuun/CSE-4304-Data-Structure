#include<iostream>
using namespace std;

int *arr;
int frontIndex=0, rearIndex=-1, capacity=100, count=0;

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
void push_front(int data){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }
    if(isEmpty()){
        rearIndex=0;
        frontIndex=0;
        arr[frontIndex]=data;
    }
    else{
        frontIndex--;
        if(frontIndex<0) frontIndex=capacity-1;
        arr[frontIndex]=data;
    }
    count++;
    display();
}
void push_back(int data){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }
    if(isEmpty()){
        rearIndex=0;
        frontIndex=0;
        arr[rearIndex]=data;
    }
    else{
        rearIndex++;
        rearIndex%=capacity;
        arr[rearIndex]=data;
    }
    count++;
    display();
}
int pop_front(){
    if(isEmpty()){
        cout<<"Deque empty"<<endl;
        return -1;
    }
    int data=arr[frontIndex];
    if(count==1){
        frontIndex=0;
        rearIndex=-1;
    }
    else{
        frontIndex++;
        frontIndex%=capacity;
    }
    count--;
    display();
    return data;
}
int pop_back(){
    if(isEmpty()){
        cout<<"Deque empty"<<endl;
        return -1;
    }
    int data=arr[rearIndex];
    if(count==1){
        frontIndex=0;
        rearIndex=-1;
    }
    else{
        rearIndex--;
        if(rearIndex<0) rearIndex=capacity-1;
    }
    count--;
    display();
    return data;
}

int main(){
    arr=new int[capacity];
    int idx;
    while(cin>>idx){
        switch(idx){
            case 1:{
                int data;
                cin>>data;
                push_front(data);
                break;
            }
            case 2:{
                int data;
                cin>>data;
                push_back(data);
                break;
            }
            case 3:{
                pop_front();
                break;
            }
            case 4:{
                pop_back();
                break;
            }
            case 5:{
                cout<<size()<<endl;
                break;
            }
            case 6:{
                break;
            }
        }
        if(idx==6){
            break;
        }
    }
    delete[] arr;
    return 0;
}