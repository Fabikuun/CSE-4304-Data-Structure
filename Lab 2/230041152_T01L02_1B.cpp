#include<iostream>
using namespace std;

typedef struct{
    int top=-1;
    int *data;
    int capacity=0;
} Stack;

void initialize(Stack *s, int n){
    s->capacity=n;
}

void print(Stack *s){
    for(int i=0;i<=s->top;i++){
        cout<<s->data[i]<<" ";
    }
    cout<<endl;
}

bool isEmpty(Stack *s){ //3
    return s->top==-1;
}

bool isFull(Stack *s){ //4
    return s->top == s->capacity-1;
}

void push(Stack *s, int value){ //1
    if(!isFull(s)){
        (s->top)++;
        s->data[s->top]=value;
        print(s);
    }
    else{
        cout<<"Overflow"<<endl;
    }
}

void pop(Stack *s){ //2
    if(!isEmpty(s)){
        (s->top)--;
        print(s);
    }
    else{
        cout<<"Underflow"<<endl;
    }
}

int size(Stack *s){ //5
    return s->top+1;
}

int top(Stack *s){ //6
    if(!isEmpty(s)){
        return s->data[s->top];
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cin>>n;
    Stack s;
    initialize(&s, n);
    int x;
    while(cin>>x && x!=-1){
        switch(x){
            case 1:{
                int value;
                cin>>value;
                push(&s, value);
                break;
            }
            case 2:{
                pop(&s);
                break;
            }
            case 3:{
                if(isEmpty(&s)){
                    cout<<"True"<<endl;
                }
                else{
                    cout<<"False"<<endl;
                }
                break;
            }
            case 4:{
                if(isFull(&s)){
                    cout<<"True"<<endl;
                }
                else{
                    cout<<"False"<<endl;
                }
                break;
            }
            case 5:{
                cout<<size(&s)<<endl;
                break;
            }
            case 6:{
                int t=top(&s);
                if(t==-1) cout<<"Underflow"<<endl;
                else cout<<t<<endl;
                break;
            }
        }
    }

}