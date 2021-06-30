#include<bits/stdc++.h>
using namespace std;

// Given an array of n positive integers and a number k. 
//Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// https://www.youtube.com/watch?v=DkOaYAfolnQ

int minSwap(int *arr, int n, int k) {
    int count = 0;
    for(int i =0;i<n;i++){
        if(arr[i]<=k){
            count += 1;
        }
    }
    // now we will create a window of length count
    // and try to find  count of elements in that window which is greater than k which we need to swap
    // minimum count of any window will be our result
    int need_swap = 0;
    for(int i =0;i<count;i++){
        if(arr[i]>k){
            need_swap += 1;
        }
    }
    int min_swap = need_swap;
    for(int j = count;j<n;j++){
        if(arr[j]>k)
          need_swap += 1;
        if(arr[j-count]>k)
          need_swap -= 1;
        min_swap = min(min_swap,need_swap);
    }
    return min_swap;
}