#include<bits/stdc++.h>
using namespace std;
int getMinvertex(bool * visited,int *  weights,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&((minVertex==-1)||weights[i]<weights[minVertex])){
            minVertex =i;
        }
    }
    return minVertex;
}
void prims(int ** edges ,int n){
    bool *  visited =  new bool[n]();
    int *  weights =  new int [n];
    int * parent =  new int [n];
    weights[0] = 0;
    parent[0]  = -1;
    for(int i=1;i<n;i++){
            weights[i] = INT_MAX;         
    }
    int count  = n-1;
    while(count--){
       // get min vertex i.e unvisited vertex with minimnum weight
        int minVertex =  getMinvertex(visited,weights,n);
        visited[minVertex] =  true;
        for(int i=0;i<n;i++){
            if(edges[minVertex][i]!=0&&!visited[i]){
                if(weights[i]>edges[minVertex][i]){
                    weights[i] = edges[minVertex][i];
                    parent[i] = minVertex;
                     }
                 }
           }
     }
     for(int i = 1;i<n;i++){
         if(parent[i]<i)
         cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
         else
          cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
     }     
}
int main(){
    int n,e;
    cin>>n>>e;
    int ** edges =  new int* [n];
    for(int i=0;i<n;i++){
        edges[i] = new int [n];
            for(int j=0;j<n;j++){
                edges[i][j] = 0;
            }
    }
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] =  w;
    }
        prims(edges,n);
    return 0;
}