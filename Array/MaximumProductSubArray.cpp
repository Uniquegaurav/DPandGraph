#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long maxProduct(int *arr, int n) {
	    ll sum_pos =1;
	    ll sum_neg =1;
	    ll sum_to = 1;
	    ll val =1;
	    for(int i = 0;i<n;i++){
            ll tempp =sum_pos;
            ll tempn  =sum_neg;
	        if(arr[i]>0){
	            sum_pos = tempp*arr[i];
	            sum_neg = min(tempn*arr[i],val);
	        }
	        if(arr[i]<0){
	            sum_pos = max((tempn*arr[i]),val);
	            sum_neg = tempp*arr[i];
	        }
	        if(arr[i]==0){
	            sum_pos =1;
	            sum_neg = 1;
	        }
            //cout<<sum_pos<<" "<<sum_neg<<endl;
	        sum_to = max(sum_to,sum_pos);
	    }
         return sum_to;
}