#include<iostream>
using namespace std;

struct Grade{
    int marks;
    string grade;

};

int binarysearch(Grade g[], int size, int score){
    int idx=0, left=0, right=size-1;
    while(left<=right){
        int mid=(left+right)/ 2;
        if(g[mid].marks<=score){
            idx=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return idx;
}

int main(){
    int lvl, trials;
    cin>>lvl>>trials;
    Grade g[1000];
    for(int i=0; i<lvl; i++){
        cin>>g[i].marks>>g[i].grade;
    }
    for(int i=0; i<trials; i++){
        int score;
        cin>>score;
        int index=binarysearch(g, lvl, score);
        cout<<g[index].grade<<endl;
    }
    return 0;
}