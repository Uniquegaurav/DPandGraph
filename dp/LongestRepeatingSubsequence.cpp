#include<bits/stdc++.h>
using namespace std;
 
//  Given a string, find the length of the longest repeating subsequence such that the two subsequences 
//  don't have same string character at the same position, i.e., 
//  any i'th character in the two subsequences shouldn't have the same index in the original string

// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

int LongestRepeatingSubsequence(string str){
        		int m = str.size();
                int n = str.size();
                int dp[m+1][n+1];
                for(int i =0;i<=m;i++){
                    dp[i][0] = 0;
                }
                for(int j =0;j<=n;j++){
                    dp[0][j] = 0;
                }
                for(int i =1 ;i<=m;i++){
                    for(int j =1 ;j<=n;j++){
                        if(str[i-1]==str[j-1]&&i!=j){
                            dp[i][j] = dp[i-1][j-1] + 1;
                        }else{
                            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                        }
                    }
                }
                return dp[m][n];
		}