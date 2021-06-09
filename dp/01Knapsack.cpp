#include<bits/stdc++.h>
using namespace std;

// You are given weights and values of N items, put these items in a knapsack of capacity W to 
// get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and
//  weights associated with N items respectively.
//  Also given an integer W which represents knapsack capacity, find out the maximum value subset of
//   val[] such that sum of the weights of this subset is smaller than or equal to W. 
// You cannot break an item, either pick the complete item or don’t pick it (0-1 property)

// using memoization
int knapsack_memo(int *weights, int *values, int n, int maxWeight,int **dp){
    if(n==0||maxWeight==0){
        return 0;
    }
    if(dp[n][maxWeight] != -1){
        return dp[n][maxWeight];
    }
    int opt1_exclude = 0 , opt2_include= 0;
    if(weights[0]<=maxWeight){
        opt2_include = knapsack_memo(weights + 1, values + 1, n -1, maxWeight - weights[0],dp) + values[0];
    }
    opt1_exclude = knapsack_memo(weights + 1, values + 1, n-1, maxWeight,dp);
    int ans = max(opt1_exclude,opt2_include);
    dp[n][maxWeight] = ans;
    return ans; 
}   
int knapsack(int *weights, int *values, int n, int maxWeight)
{	
    // starting from ith element and maximum  weight allowed w answer will be same 
    int **dp = new int*[n+1];
    for(int i =0;i<=n;i++){
        dp[i] = new int[maxWeight+1];
        for(int j = 0 ;j<=maxWeight ;j++){
            dp[i][j] = -1;
        }
    }
	return knapsack_memo(weights,values,n,maxWeight,dp);
}

// using dynamic programming

