#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n){
     // initially dividing into two part sorted(i =0) and unsorted(i =1 to n-1)
        for(int i =1;i<n;i++){
            // now for every arr[i] (key)
            // we will try to find a position j in sorted part 
            // for which arr[i] > arr[j] we are shifting other elements to the right and 
            // creating a gap to place arr[i] (key) to jth position
            int j = i;
            int key = arr[i];
            while(j>0&&arr[j-1]>key){
                arr[j] = arr[j-1];
                j -= 1;
            }
            arr[j] = key;
        }
}