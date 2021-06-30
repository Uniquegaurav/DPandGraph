 #include<bits/stdc++.h>
 using namespace std;
//  Question link : https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#
//  Given an array arr of size n and an integer X.
//   Find if there's a triplet in the array which sums up to the given integer X.

// Two pointers approach 

 bool find3Numbers(int arr[], int n, int X)
    {
        sort(arr,arr+n);
        for(int i =0;i<n;i++){
             int sum = X -arr[i];
             int j = i + 1;
             int k = n-1;
             while(j<k){
                 if(arr[j]+arr[k]==sum) return true;
                 else if(arr[j]+arr[k]<sum){
                     j += 1;
                 }else{
                     k -= 1;
                 }
             }
        }
        return false;
    }

// Hash map Approcah 

 void sumi(){
    int n,x ;
    cin>>n>>x;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    bool is_found = false; // this will store if triplet is found or not
    
    for(int i =0;i<n-1&&(!is_found);i++){
        
        int req_sum = x - arr[i];
        unordered_set<int>  s;
        for(int j = i+1 ;j<n;j++){
            
           if(s.find(req_sum-arr[j])!=s.end()){
                is_found = true;
                break;
            }
            s.insert(arr[j]);
        }
    }
    if(is_found){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
}