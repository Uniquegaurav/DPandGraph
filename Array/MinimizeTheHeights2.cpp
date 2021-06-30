#include<bits/stdc++.h>
using namespace std;

// Given an array arr[] denoting heights of N towers and a positive integer K, 
// you have to modify the height of each tower either by increasing or decreasing them by K only once. 
// After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the height of shortest and longest 
// towers after you have modified each tower.

int getMinDiff(int arr[], int n, int k) { 
        sort(arr, arr+n);
        int minEle, maxEle;
        int result = arr[n-1] - arr[0];
        
        for(int i =1; i<=n-1; i++){
            if(arr[i]>=k){
                maxEle = max(arr[i-1] + k, arr[n-1]-k);
                minEle = min(arr[0]+k, arr[i]-k);
                
                result = min(result, maxEle-minEle);
            }
        }
        return result;
   }