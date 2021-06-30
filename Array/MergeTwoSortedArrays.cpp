#include<bits/stdc++.h>
using namespace std;
// problem link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
// Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


// method 1 with extra space 
void merge(int arr1[], int arr2[], int n, int m) {
    	int temp[n+m];
        int i = 0;
        int j = 0;
        int k =0;
        while(i<n&&j<m){
         	if(arr1[i]<arr2[j]){
                temp[k++] = arr1[i++];
            }else{
                temp[k++] = arr2[j++];
            }
        }
        while(i<n){
            temp[k++] = arr1[i++];
        }
        while(j<m){
            temp[k++] = arr2[j++];
        }  
        for(int i =0;i<k;i++){
            if(i<n){
                    arr1[i] = temp[i];
            }else{
                    arr2[i-n] = temp[i];
            }
        }
}

// method 2 without extra space 

void merge(int arr1[], int arr2[], int n, int m) { 
	    int i = n-1;
	    int j =0;
	    while(i>=0&&j<m){
	        if(arr1[i]>arr2[j]){
	            swap(arr1[i],arr2[j]);
	        }
	        i -= 1;
	        j += 1;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
}
