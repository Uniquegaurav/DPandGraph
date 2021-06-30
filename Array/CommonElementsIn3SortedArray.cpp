#include<bits/stdc++.h>
using namespace std;
// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){   
    int i =0 , j=0,k =0;
    vector<int> v;
    set<int> s;
    while((i<n1)&&(j<n2)&&(k<n3)){ 

        if(A[i]==B[j]&&B[j]==C[k]){
            s.insert(A[i]);
            i++;  j++; k++;

        }else if(A[i]<B[j]){
            i++;

        }else if(B[j]<C[k]){
            j++;      

        }else{
            k++;
            
        }
    }
    for(auto i : s){
        v.push_back(i);
    }
    return v;
}