 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int ll;
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

 // solution 1 
 int maxSubarraySum(int arr[], int n){ 
        int max_sum = INT_MIN;
        int until = 0;
        for(int i =0;i<n;i++){
            until += arr[i];
            if(until>max_sum)
                max_sum = until;
            if(until<0)
                until = 0;
        }
        return max_sum;
}
// solution 2
void solve(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
     // Applying Kadane's Algorithm
    ll  curr_max = arr[0];
    ll max_sum =arr[0];
    //v.push_back(curr_max);
    for(int i =1;i<n;i++){
        ll opt1 = arr[i];
        ll opt2 = curr_max + arr[i];
        if(opt1>=opt2){
            curr_max = opt1;
        }else{
            curr_max = opt2;
        }
        if(curr_max>max_sum){
            max_sum = curr_max;
        }
    }
    cout<<max_sum<<endl;
}