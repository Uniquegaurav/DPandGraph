#include<bits/stdc++.h>
using  namespace std;
// Given a sorted and rotated array A of N distinct elements which is rotated at some point, 
// and given an element key. The task is to find the index of the given element key in the array A.

// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1#
int bsearch(int A[],int l ,int h,int key){
        while(l<=h){
            int mid = (l+h)/2;
            if(A[mid]==key){
                return mid;
            }else if(A[mid]<key){
                l = mid + 1;
            }else{
                h = mid -1;
            }
        }
        return -1;
}
int search(int A[], int l, int h, int key){
         int idx = h-1; 
         for(int  i=0;i<h-1;i++){
             if(A[i+1]<A[i]){
                 idx = i;
             }
         }
         int halfs = bsearch(A,l,idx,key);
         if(halfs!=-1){
             return halfs;
         }
         return bsearch(A,idx+1,h-1,key);
}