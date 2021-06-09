// Given two integers n and r, find nCr.
// Since the answer may be very large, calculate the answer modulo 109+7.
#include<bits/stdc++.h>>
using namespace std;
int m = 1000000007;
    int nCr(int n, int r){
          if(r>n){
              return 0;
          }
          // nCr= n-1Cr + n-1Cr-1
          int dp[n+1][r+1];
          for(int i =0;i<=n;i++){
              for(int j= 0;j<=r;j++){
                  if(j==0){
                      dp[i][j]= 1;
                  }else if(i==0){
                      dp[i][j]= 0;
                  }else{
                      dp[i][j]= 0;
                  }
              }
          }
          dp[0][0]=1;
          for(int i =1;i<=n;i++){
              for(int j =1;j<=min(i,r);j++){
                  dp[i][j] = (dp[i-1][j]%m + dp[i-1][j-1]%m)%m;
              }
          }
          return dp[n][r];
          
    }