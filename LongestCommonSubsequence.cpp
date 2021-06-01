// Longest Common Subsequence

// Given two sequences, find the length of longest subsequence present in both of them. 
// Both the strings are of uppercase.


// using memoization
#include<bits/stdc++.h>
using namespace std;

int lcs_mem(string s , string t,int **dp){

    int m = s.size();
    int n = t.size();
    if(s.size()==0||t.size()==0){
        return 0;
    }
    if(dp[m][n] !=-1){
        return dp[m][n];
    }
    int ans;
    if(s[0]==t[0]){
       ans  = 1 + lcs_mem(s.substr(1),t.substr(1),dp);
    }else{  
        int a = lcs_mem(s.substr(1),t,dp);
        int b = lcs_mem(s,t.substr(1),dp);
        int c = lcs_mem(s.substr(1),t.substr(1),dp);
        ans = max(a,max(b,c));
    }   
   
    dp[m][n] = ans;
    return ans;
}

int lcs(string s ,string t){
    int m =  s.size();
    int n = t.size();
    int ** dp = new int*[m];
    for(int i =0;i<m;i++){
        dp[i] = new int[n];
        for(int j =0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    lcs_mem(s,t,dp);
}

// dynamic Programming 

int lcs(string s , string t){
    
}