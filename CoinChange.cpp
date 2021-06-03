#include<bits/stdc++.h>>
using namespace std;


//using memoization
int countWaysToMakeChange_mem(int d[] ,int numD,int value,int **dp){
    if(value==0){
        return 1;
    }
    if(value<0||numD==0){
        return 0;
    }
    if(dp[value][numD]!= -1){
        return dp[value][numD];
    }
    int poss1 = countWaysToMakeChange_mem(d,numD,value-d[0],dp);
    int poss2 = countWaysToMakeChange_mem(d+1,numD-1,value,dp);
    dp[value][numD] = poss1 + poss2;
    return poss1 + poss2;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	int **dp = new int*[value+1];
    for(int i =0;i<=value;i++){
        dp[i] = new int[numDenominations+1];
        for(int j =0;j<=numDenominations;j++){
            dp[i][j] = -1;
        }
    }
    return countWaysToMakeChange_mem(denominations,numDenominations,value,dp);
}




// using dynamic programming

