//Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> Ndegree(V,0);
	    for(int i =0;i<V;i++){
	        for(int j : adj[i]){
	            Ndegree[j] = Ndegree[j] + 1;
	        }
	    }
	    queue<int> q;
	    for(int i =0;i<V;i++){
	        if(Ndegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int front = q.front();
	        ans.push_back(front);
	        q.pop();
	        for(int j : adj[front]){
	            Ndegree[j] = Ndegree[j] - 1;
	            if(Ndegree[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    return ans;
	}
};