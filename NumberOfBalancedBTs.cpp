// Given an integer h, find the possible number of balanced binary trees of height h.
//  You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so, return output modulus 10^9 + 7.
// Time complexity should be O(h).

#include<bits/stdc++.h>
using namespace std;
int m = 1000000007;

/// using memoization
int balancedBTsHelp(int n,int * dp){
 	   
    if(n==1||n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int x = balancedBTsHelp(n-1,dp);
    int y = balancedBTsHelp(n-2,dp);
    int temp1 = (int)((long)(x)*x%m);
    int temp2 = (int)(2*(long)(x)*y%m);
    int ans = (temp1+temp2)%m;
    dp[n] = ans;
    return ans;
}
int balancedBTs(int n) {
    int * dp = new int[n+1];
    for(int i =0;i<=n;i++){
        dp[i] = -1;
    }
    return balancedBTsHelp(n,dp);
}