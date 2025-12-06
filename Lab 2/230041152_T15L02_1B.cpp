#include<iostream>
using namespace std;

typedef struct{
    int top=-1;
    int *data;
    int capacity=0;
} Stack;

void initialize(Stack *s, int n){
    s->capacity=n;
    s->data=new int[n];
}

void print(Stack *s){
    for(int i=0;i<=s->top;i++){
        cout<<s->data[i]<<" ";
    }
    cout<<endl;
}

bool isEmpty(Stack *s){
    return s->top==-1;
}

bool isFull(Stack *s){
    return s->top == s->capacity-1;
}

void push(Stack *s, int value){
    if(!isFull(s)){
        (s->top)++;
        s->data[s->top]=value;
    }
    else{
        cout<<"Overflow !!!"<<endl;
    }
}

void pop(Stack *s){
    if(!isEmpty(s)){
        (s->top)--;
    }
    else{
        cout<<"Underflow"<<endl;
    }
}

int size(Stack *s){
    return s->top+1;
}

int top(Stack *s){
    if(!isEmpty(s)){
        return s->data[s->top];
    }
    else{
        return 0;
    }
}

void printStatus(Stack *s){
    cout<<"Size : "<<size(s)<< endl;
    cout<<"Stack elements :";
    for(int i=0; i<=s->top; i++){
        cout<<" "<<s->data[i];
    }
    cout<<endl;
    cout<<"Top Element : "<<top(s)<<endl;
    cout<<"isFull : "<<(isFull(s) ? "True" : "False")<<endl;
    cout<<"isEmpty : "<<(isEmpty(s) ? "True" : "False")<<endl;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    Stack s;
    initialize(&s, n);
    while(1){
        string str;
        getline(cin, str);
        if (str == "/") break;
        if(str[0]=='+'){
            string numStr = str.substr(1);
            while(!numStr.empty() && numStr[0]==' ') numStr.erase(0,1);
            while(!numStr.empty() && numStr.back()==' ') numStr.pop_back();
            if(!numStr.empty()){
                int value = stoi(numStr);
                push(&s,value);
                printStatus(&s);
                cout<<endl;
            }
        }
        else if(str[0]=='-'){
            pop(&s);
            printStatus(&s);
            cout<<endl;
        }
    }
    delete[] s.data;
    return 0;
}
