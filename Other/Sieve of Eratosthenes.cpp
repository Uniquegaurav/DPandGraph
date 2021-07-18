#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool * seive = new bool[n+1];
    for(int i = 0;i<=n;i++){
        seive[i] = true;
    }
    seive[0] = false;
    seive[1] = false;
    for(int i =2 ;i*i<=n;i++){
        if(seive[i]){
        for(int j = i*i;j<=n;j += i){
            seive[j]= false;
          }
       }
    }
    int count  =0;
    for(int i =0;i<=n;i++){
        if(seive[i])
        count++;
    }
    cout<<count<<endl;
}