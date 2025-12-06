#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    int x;
    while(cin>>x && x!=-1){
        pq.push(x);
    }
    while(pq.size()>1){
        int y=pq.top();
        pq.pop();
        int x=pq.top();
        pq.pop();
        if(y!=x){
            pq.push(y-x);
        }
    }
    cout<<(pq.empty()?0:pq.top())<<endl;
    return 0;
}