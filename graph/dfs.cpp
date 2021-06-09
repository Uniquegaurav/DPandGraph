#include<bits/stdc++.h>
using namespace std;
void dfs(int ** edges,int n,int sv,bool * visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(i==sv) continue;
        if(edges[sv][i]&&!visited[i]){
            dfs(edges,n,i,visited);
        }
    }
}
void dfs_allcomp( int **edges, int n){
    bool *visited = new bool[n];
    for(int i =0 ;i<n;i++){
        visited[i] = false;
    }
    for(int i =0;i<n;i++){
        if(!visited[i]){
             dfs(edges,n,i,visited);
        }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i =0;i<n;i++){
        edges[i]= new int[n];
        for(int j =0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i =0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
   dfs_allcomp(edges,n);
}