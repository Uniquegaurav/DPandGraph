#include<bits/stdc++.h>
using namespace std;
//Given an array of integers (A[])  and a number x, 
//find the smallest subarray with sum greater than the given value

int sb(int arr[], int n, int x){
        int i = 0 ,j = 0;
        int sum =0 ;
        int min_length = INT_MAX;
        while(j<n){
            if(arr[j]>x) return 1;
            if(sum<=x){
                sum += arr[j];
            }
            if(sum>x&&i<j){
                min_length = min(min_length,(j-i+1));
                sum -= arr[i];
                i += 1;
            }
            if(sum<=x) j += 1;
        }
        return min_length;
}