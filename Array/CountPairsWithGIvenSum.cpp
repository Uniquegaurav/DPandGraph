// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// Given an array of N integers, and an integer K, 
// find the number of pairs of elements in the array whose sum is equal to K.

#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
         map<int,int> m;
         for(int i =0;i<n;i++) 
            m[arr[i]] += 1;
         int value =0 ;
         for(int i =0;i<n;i++){
             value += m[k-arr[i]]; // finding count of second pair 
             if(k-arr[i] == arr[i]){ // if second pair is same as first then decrease it by 1
                 value -= 1;
             }
         }
         return value/2;
    }
