#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1
// Given an array Arr[] of size L and a number N, 
// you need to write a program to find if there exists a pair of elements in the array whose difference is N

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    int i = 0;
    int j = 1;
    while(j<size&&i<size){
         int diff = arr[j] - arr[i];
         if(diff==n){
             return true;
         }
         if(diff>n){
             i += 1;
         }else{
             j += 1;
         }
    }
    return false;
}