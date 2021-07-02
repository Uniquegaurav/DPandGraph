#include<bits/stdc++.h>
using namespace std;

static bool  compare(int a,int b){
        int counta = 0;
        int countb =0 ;
        while(a>0){
            counta += (a&1);
            a = a>>1;
        }
        while(b>0){
            countb += (b&1);
            b = b>>1;
        }
        return counta>countb;
}
void sortBySetBitCount(int arr[], int n){
        stable_sort(arr,arr+n,compare);
}     