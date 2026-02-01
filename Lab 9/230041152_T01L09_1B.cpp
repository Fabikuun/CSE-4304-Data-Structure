#include<iostream>
using namespace std;
int table[100];
int tableSize;
int inserted;

int hash(int x){
    return x%tableSize;
}
int hash2(int x){
    return 7-(x%7);
}
void insert()