#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA .
class Solution{
    public:
	    vector<string> find_helper(string s){
	       int n = s.size();
	       vector<string> ans;
	       if(n==1){
	           ans.push_back(s);
	           return ans;
	       }
	       for(int i =0;i<s.size();i++){
	           string small =  s;
	           small.erase(small.begin() + i);
	           vector<string> smallans = find_helper(small);
	           for(auto val : smallans){
	               ans.push_back(s[i] + val);
	           }
	       }
	       return ans;
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans =  find_helper(S);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};