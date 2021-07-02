//  You are given an array arr[] of size n. 
// Find the total count of sub-arrays having their sum equal to 0.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll findSubarray(vector<ll> arr, int n ) {    
        unordered_map<ll, ll> m;
        ll sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0){
                ans++;
            }
            ans += m[sum];
            m[sum]++;
        }
        return ans;
        
    }