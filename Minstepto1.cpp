 
/* problem statement  : 

 Given a positive integer 'n',
  find and return the minimum number of steps that 'n' has to take to get reduced to 1. 
  You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
*/


#include<bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n,int * arr)
{
  if(n<=1){
      return 0;
  }
  if(arr[n] != -1){
      return arr[n];
  }
    
  int minstep  = countMinStepsToOne(n-1 ,arr);
    
  if(n%2==0){
     minstep = min(countMinStepsToOne(n/2 ,arr) , minstep) ;
  }
  if(n%3==0){
     minstep = min(countMinStepsToOne(n/3,arr) , minstep) ;
  }
    arr[n] = minstep + 1;
    return minstep + 1;
}

int countStepsToOne(int n)
{		
     int * arr  = new int[n+1];
	 for(int i=0;i<=n;i++){
         arr[i] =  -1;
     }
    return countMinStepsToOne(n,arr);
}