#include<bits/stdc++.h>
using namespace std;

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is
//  missing and one number 'B' occurs twice in array. Find these two numbers.

//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

 int *findTwoElement(int *arr, int n) {
        int miss ,repeat;
        for(int i =0;i<n;i++){
            int idx = abs(arr[i])-1;
            if(arr[idx]<0){
                repeat  = idx + 1;
            }else{
                arr[idx] = -1*arr[idx];
            }
        }
        for(int i =0;i<n;i++){
            if(arr[i]>0){
                miss = i + 1;
                break;
            }
        }
        int * ans = new int[2];
        ans[0] = repeat;
        ans[1] =miss;
        return ans;
    }