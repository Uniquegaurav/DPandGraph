#include<bits/stdc++.h>
using namespace std;

// Given a sorted array arr containing n elements with possibly duplicate elements, 
// the task is to find indexes of first and last occurrences of an element x in the given array.

vector<int> find(int arr[], int n , int x )
{
    int left  = 0;
    int right = n-1;
    int first = -1;
    int last  = -1;
    int mid;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==x){
            first = mid;
            right = mid-1;
        }else if(arr[mid]>x){
            right  = mid-1;
        }else{
            left = mid + 1;
        }
    }
    left = 0 ,right = n-1;
    
     while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==x){
            last = mid;
            left  = mid+1;
        }else if(arr[mid]>x){
            right  = mid-1;
        }else{
            left = mid + 1;
        }
    }
    return vector<int>({first, last});
}