#include<bits/stdc++.h>
using namespace std;
// Given an array of integers and another number. 
// Find all the unique quadruple from the given array that sums up to the given number.

vector<vector<int> > fourSum(vector<int> &arr, int k) {
        set<vector<int>> ans_set;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i =0;i<n-3;i++){
            for(int j =i+1;j<n-2;j++){
                int r = j + 1;
                int s = n-1;
                while(r<s){
                    int sum = arr[i]+ arr[j] + arr[r]+ arr[s];
                    if(sum==k){
                         ans_set.insert({arr[i],arr[j],arr[r],arr[s]});
                        r += 1 ; s -=1 ;
                    }else if(sum<k){
                        r += 1;
                    }else{
                        s -= 1;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i :  ans_set) ans.push_back(i);
        return ans;
    }