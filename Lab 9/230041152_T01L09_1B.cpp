#include<iostream>
using namespace std;

int table[100];

int hash2(int x){
    return 7-(x%7);
}
int Hash(int x, int size){
    return x%size;
}
void insert(int x, int choice, int table[], int size, int &insertCount){
    int h=Hash(x,size);
    for(int i=0; i<6; i++){
        int idx;
        switch(choice){
        case 1:
            idx=(h+i)%size;
            break;
        case 2:
            idx=(h+i*i)%size;
            break;
        case 3:
            idx=(h+i*hash2(x))%size;
            break;
        }
        if(table[idx]==-1){
            table[idx]=x;
            insertCount++;
            double loadFactor=(double)insertCount/size;
            cout<<"Inserted : Index-"<<idx<<" (L.F="<<loadFactor<<")"<<endl;
            return;
        }
        else{
            cout<<"Collision at Index-"<<idx<<endl;
        }
    }
    cout<<"Input Abandoned"<<endl;
}

int main(){
    int choice, tableSize, Q;
    cin>>choice>>tableSize>>Q;
    for(int i=0; i<tableSize; i++) table[i]=-1;
    int insertCount=0;
    for(int i=0; i<Q; i++){
        int x;
        cin>>x;
        insert(x, choice, table, tableSize, insertCount);
    }
    return 0;
}