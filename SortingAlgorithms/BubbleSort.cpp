#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n){
        for(int k =1;k<n;k++){  // total n-1 times repeating the steps
            int flag = 0;
            for(int j =0 ;j<=n-k-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    flag =1;
                }
            }
            if(flag==0) break;
        }
    }
};