// Given an array of n distinct elements. 
// Find the minimum number of swaps required to sort the array in strictly increasing order.
#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums)
	{   
	    int n = nums.size();
	    vector<pair<int,int>> v(n);
	    for(int i =0;i<n;i++){
	        v[i] = {nums[i],i};
	    }
	    int count  =0;
	    sort(v.begin(),v.end());
	    for(int i =0;i<n;i++){
	        if(v[i].second==i)
	            continue;
	       else{
	           count += 1;
	           swap(v[i],v[v[i].second]);
	           i -= 1;
	       }
	    }
	    return count;
	}