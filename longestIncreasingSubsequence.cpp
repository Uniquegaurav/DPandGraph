#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int* arr, int n) {
     int * dp = new int[n];
       dp[0] = 1;
       for(int i =1;i<n;i++){
           dp[i] = 1;
           for(int j = i-1;j>=0;j--){
               if(arr[i]>arr[j]){
                   dp[i] = max(dp[i],dp[j] + 1);
               }
           }
       }
       int longest  = 0;
       for(int i =0;i<n;i++){
           longest  = max(longest, dp[i]);
       }
       return longest;
}