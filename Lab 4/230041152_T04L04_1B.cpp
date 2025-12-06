#include<iostream>
#include<string>
using namespace std;

struct Wizard{
    string name;
    int age;
    string house;
    int order;
};

Wizard heap[1000];
int n=0;

void heapify(int i){
    int left=2*i, right=2*i+1, largest=i;
    if(left<=n){
        if((heap[left].age>heap[largest].age) || (heap[left].age==heap[largest].age && heap[left].order<heap[largest].order)){
            largest=left;
        }
    }
    if(right<=n){
        if((heap[right].age>heap[largest].age) || (heap[right].age==heap[largest].age && heap[right].order<heap[largest].order)){
            largest=right;
        }
    }
    if(largest!=i){
        swap(heap[i],heap[largest]);
        heapify(largest);
    }
}

void insertWiz(Wizard w){
    n++;
    heap[n]=w;
    int i=n;
    while(i>1){
        int parent=i/2;
        if((heap[parent].age<heap[i].age) ||(heap[i].age == heap[parent].age && heap[i].order<heap[parent].order)){
            swap(heap[parent],heap[i]);
            i=parent;
        }
        else{
            break;
        }
    }
}

Wizard extractMax(){
    Wizard maxWiz=heap[1];
    heap[1]=heap[n];
    n--;
    if(n>0) heapify(1);
    return maxWiz;
}

int main(){ 
    char str;
    int orderCount=0;
    while(cin>>str){
        if(str=='I'){
            cin>>ws;
            string line;
            getline(cin,line);
            Wizard w;
            int i=0;
            string name="",num="",house="";
            while(i<line.size() && !(line[i]>='0' && line[i]<='9')){
                name+=line[i];
                i++;
            }
            while(name.size()>0 && name.back()==' ') name.pop_back();
            while(i<line.size() && (line[i]>='0' && line[i]<='9')){
                num+=line[i];
                i++;
            }
            while(i<line.size() && line[i]==' ') i++;
            while(i<line.size()){
                house+=line[i];
                i++;
            }
            w.name=name;
            w.age=stoi(num);
            w.house=house;
            w.order=orderCount++;
            insertWiz(w);
        }
        else if(str=='S'){
            if(n>0){
                Wizard served=extractMax();
                cout<<"Name: "<<served.name<<", Age: "<<served.age<<", House: "<<served.house<<endl;
            }
        }
        else if(str=='X'){
            break;
        }
    }
    return 0;
}