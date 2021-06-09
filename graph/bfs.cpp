#include<bits/stdc++.h>
using namespace std;
void bfs(int ** edges,int n,int sv,bool * visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i = 0;i<n;i++){
            if(edges[curr][i]&&!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void bfs_allcomp( int **edges, int n){
    bool *visited = new bool[n];
    for(int i =0 ;i<n;i++){
        visited[i] = false;
    }
    for(int i =0;i<n;i++){
        if(!visited[i]){
             bfs(edges,n,i,visited);
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
    bfs_allcomp(edges,n);
}