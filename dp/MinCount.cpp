// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
// The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.


#include<bits/stdc++.h>
using namespace std;

int MinSquares(int n){
	    // solving this problem with dynamic programming approach
	    int * dp = new int[n+1];
	    dp[0] = 0; // if n == 0 then ans will be  0
	    dp[1] = 1; // if n == 1 then we will do just 1^2 and answer will be 1
	    for(int i = 2;i<=n;i++){
	        dp[i] = INT_MAX;
	        for(int j = 1 ; j*j<= i ;j++){
	            
	            //  from j == 1 to j < underroot i we are selecting a number
	            //  if we include this number in number of squares then we just have
	            // to find ans for (i - j*j) and that ans will be at dp[i -j*j] and then
	            // ans will be  dp[i-j*j] + 1 because we are including j  also
	            //  we will take minimum for all possible value of j
	            dp[i] = min(dp[i] , dp[i-j*j] + 1);
	        }   
	    }
	   return dp[n];
}