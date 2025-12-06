#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    string st,ds;
    deque<int> students;
    deque<int> dishes;
    cin>>st;
    int cnt0=0, cnt1=0;
    for(int i=0; i<N; i++){
        int x;
        cin>>x;
        students.push_back(x);
        if(x==0) cnt0++;
        else cnt1++;
    }
    cin>>ds;
    for(int i=0; i<N; i++){
        int x;
        cin>>x;
        dishes.push_back(x);
    }
    for(int dish: dishes){
        if(dish==0){
            if(cnt0>0) cnt0--;
            else break;
        }
        else{
            if(cnt1>0) cnt1--;
            else break;
        }
    }
    cout<<(cnt0+cnt1)<<endl;
    return 0;
}