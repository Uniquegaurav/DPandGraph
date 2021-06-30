// Given an array of integers Arr of size N and a number K. 
// Return the maximum sum of a subarray of size K.

//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1/

#include<bits/stdc++.h>
using namespace std;
int maximumSumSubarray(int K, vector<int> &Arr , int N){
        
        int currentsum = 0;
        int maxsum =0 ;
        for(int i =0;i<K;i++){
            currentsum  += Arr[i];
        }
        maxsum = currentsum;
        for(int i = K;i<N;i++){
            currentsum -= Arr[i-K];
            currentsum +=  Arr[i];
            maxsum = max(maxsum,currentsum);
        }
        return maxsum;
}