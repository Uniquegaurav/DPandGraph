// An integer matrix of size (M x N) has been given. 
// Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
// From a cell (i, j), you can move in three directions:
// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"

// The cost of a path is defined as the sum of each cell's values through which the route passes.


#include<bits/stdc++.h>
using namespace std;

 // using memoization 
int minCostPathHelp(int ** input ,int m,int n,int **dp, int i ,int j){
    
    if(i==m-1&&j==n-1){
        return input[i][j];
    }
    if(i>=m||j>=n){
        return INT_MAX;
    }
      if(dp[i][j] != -1){
        return dp[i][j];
    }
    int x = minCostPathHelp(input,m,n,dp,i+1,j);    
    int y = minCostPathHelp(input,m,n,dp,i+1,j+1);    
    int z = minCostPathHelp(input,m,n,dp,i,j+1);
    int ans = min(x, min(y,z)) + input[i][j];
    dp[i][j] = ans;
    return ans;
}
int minCostPath(int **input, int m, int n){
    int **dp = new int *[m];
    for(int i =0; i<m;i++){
        dp[i] = new int[n];
        for(int j = 0; j<n; j++){
            dp[i][j] = -1;
        }
    }
    return minCostPathHelp(input,m,n,dp,0,0);   
}

// using dynamic programming 

int minCostPath(int **input, int m, int n){

    int **dp = new int *[m];
    for(int i =0; i<m;i++){
        dp[i] = new int[n];
    }
    dp[m-1][n-1] =  input[m-1][n-1];
    for(int i = m-2 ;i>=0;i--){
        dp[i][n-1] = dp[i+1][n-1] + input[i][n-1];
    }
    for(int j = n-2 ;j >=0 ;j--){
        dp[m-1][j] = dp[m-1][j+1] + input[m-1][j];
    }
    for(int i = m-2 ; i>=0;i--){
        for(int j  =n-2; j>=0 ;j--){
            dp[i][j] = min(min(dp[i][j+1],dp[i+1][j]) , dp[i+1][j+1]) + input[i][j];
        }
    }
    return dp[0][0];
}