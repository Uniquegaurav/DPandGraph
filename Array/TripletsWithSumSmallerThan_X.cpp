	#include <bits/stdc++.h>
    using namespace std;

    // Given an array arr[] of distinct integers of size N and a sum value X, 
    //the task is to find count of triplets with the sum smaller than the given sum value X.
    
    // https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#

    long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long  count  =0 ;
	    for(int i =0;i<n-1;i++){
	        int j = i+1;
	        int k =n-1;
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k]<sum){
	               // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
	                 count += (k-j);  // important change
	                 j += 1;
	            }else{
	                k -= 1;
	            }
	        }
	    }
	    return count;
	}