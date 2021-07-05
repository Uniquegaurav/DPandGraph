#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n){
        for(int i =0;i<n;i++){
            // finding the min element in range (i -> n-1)
            int min_val = 1e9;
            int min_idx = i;
            for(int j =i ;j<n;j++){
                if(arr[j]<min_val){
                    min_val = arr[j];
                    min_idx = j;
                }
            }
            // and swapping the min element with ith element
            swap(arr[i],arr[min_idx]);
        }
}