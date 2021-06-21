 
// Kosaraju's Algorithm

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges,int sv,unordered_set<int> &visited,stack<int> &finsihedVert){
    visited.insert(sv);
    for(int i : edges[sv]){
        if(visited.count(i)==0){
            dfs(edges,i,visited,finsihedVert);
        }
    }
    finsihedVert.push(sv);
}
void dfs2(vector<int>* edges,int sv,unordered_set<int> &visited,unordered_set<int> &component){
    visited.insert(sv);
    component.insert(sv);
    for(int i : edges[sv]){
        if(visited.count(i)==0){
            dfs2(edges,i,visited,component);
        }
    }
}
vector<unordered_set<int>> getSCC(vector<int>* edges,vector<int>* edgesT,int n){
    unordered_set<int> visited;
    stack<int> finsihedVert;
    for(int i =0;i<n;i++){
        if(visited.count(i)==0){
            dfs(edges,i,visited,finsihedVert);
        }
    }
    vector<unordered_set<int>> output;
    visited.clear();
    while(!finsihedVert.empty()){
        int start = finsihedVert.top();
        finsihedVert.pop();
        if(visited.count(start)==0){
            unordered_set<int> component;
            dfs2(edgesT,start,visited,component);
            output.push_back(component);
        }
    }
    return output;
}
int main(){
    int n ,e;
    cin>>n>>e;
    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n];
    for(int i =0;i<e;i++){
        int f,s; cin>>f>>s;
        edges[f-1].push_back(s-1);
        edgesT[s-1].push_back(f-1);
    } 
    vector<unordered_set<int>> output = getSCC(edges,edgesT,n);
    for(auto s : output){
        for(auto i : s){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}