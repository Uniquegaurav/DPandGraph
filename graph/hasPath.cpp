// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
// check if there exists any path between them or not. Print true if the path exists and false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool hasPath(int **  edges,int n,int sv,int ev,bool * visited){
    if(sv==ev){
        return true;
    }
    visited[sv] = true;
        for(int i=0;i<n;i++){
            if(edges[sv][i]==1&&!visited[i]){
                if(hasPath(edges,n,i,ev,visited))
                    return true;
                 }
            }
        return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    int ** edges  = new int *[n];
    for(int i=0;i<n;i++){
        edges[i] = new int [n];
        for(int j =0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i =0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] =1;
        edges[s][f] = 1;
    }    
    bool  *  visited =  new bool[n];
    for(int i=0;i<n;i++){
        visited[i] =false;
    }
    int sv,ev;
    cin>>sv>>ev;
    bool ans=  hasPath(edges,n,sv,ev,visited);  
    if(ans)
        cout<<"true"<<endl;
    else 
        cout<<"false"<<endl;
   
    return 0;
}