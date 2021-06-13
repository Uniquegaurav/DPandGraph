// Code : All connected components
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. 
// And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space).
//  Order of different components doesn't matter.

#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges ,int n,int sv,bool *visited,set<int> &ans){
    visited[sv] = true;
    ans.insert(sv);
    for(int i =0;i<n;i++){
        if(edges[sv][i]&&!visited[i])
          dfs(edges,n,i,visited,ans);
    }
}
vector<set<int>> getComponents(int **edges,int n){
    bool * visited = new bool[n];
    for(int i =0;i<n;i++){
        visited[i] = false;
    }
    vector<set<int>> output;
    for(int i =0;i<n;i++){
        if(!visited[i]){
            set<int> ans;
            dfs(edges,n,i,visited,ans);
            output.push_back(ans);
        }
    }
    return output;
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i =0;i<n;i++){
        edges[i] = new int[n];
        for(int j =0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i =0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    vector<set<int>> output = getComponents(edges,n);
    for(auto s : output){
        for(auto i : s){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
