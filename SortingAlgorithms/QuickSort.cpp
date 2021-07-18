#include<bits/stdc++.h>
using namespace std;
int pivot(int input[] ,int left ,int right){
    int piv = input[left];
    int i = left ;
    int j = right;
    while(i<j){
         while(input[i]<=piv){
             i += 1;
         }
         while(input[j]>piv){
             j -= 1;
         }
        if(i<j){
            swap(input[i],input[j]);
        }
    }
    swap(input[left],input[j]);
    return j ;
}


void QuickSort(int input[],int left ,int right){
    if(left>=right){
        return;
    }
    int p  = pivot(input,left,right);
    QuickSort(input, left , p-1);
    QuickSort(input,p+1,right);
    
}
void quickSort(int input[], int size) {
    int left = 0;
    int right = size-1;
    QuickSort(input,left,right);

}
