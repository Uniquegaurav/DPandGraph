// Code : Get Path - BFS
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
// find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.

#include<bits/stdc++.h>
using namespace std;
void getPath(int **edges,int n,int sv,int ev,vector<int>& ans){
    bool  *  visited =  new bool[n];
    for(int i=0;i<n;i++){
        visited[i] =false;
    }
    queue<int> q;
    map<int,int> m;
    int flag =0;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int next =  q.front();
        q.pop();
        for(int i =0;i<n;i++){
            if(edges[next][i]==1&&!visited[i]){
                q.push(i);
                visited[i] = true;
                m[i] = next;
                if(i==ev){
                    ans.push_back(ev);
                    int temp = ev;
                    while(temp!=sv){
                        temp = m[temp];
                        ans.push_back(temp);
                    }
                    flag =1;
                    break;
                }
            }
        }
        if (flag==1) break;
    }
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
    int sv,ev;
    cin>>sv>>ev;
    vector<int> ans;
    getPath(edges,n,sv,ev,ans);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}