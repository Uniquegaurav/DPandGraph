#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int n,int sv,vector<int> adj[],bool *visited){
        visited[sv] = true;
        for(int i : adj[sv]){
            if(!visited[i])
                dfs(n,i,adj,visited);
        }
    }
	int findMotherVertex(int V, vector<int>adj[]){   
	    int n = V;
	    bool * visited = new bool[n];
	    for(int i =0;i<n;i++){
	        visited[i] =false;
	    }
	    int mother_node  = -1;
	    for(int i =0;i<n;i++){
	        if(!visited[i]){
	            dfs(n,i,adj,visited);
	            mother_node  = i;
	        }
	    }
	    for(int i =0;i<n;i++){
	        visited[i] = false;
	    }
	    dfs(n,mother_node,adj,visited);
	    for(int i =0;i<n;i++){
	        if(!visited[i])
	            mother_node  = -1;
	    }
	    return mother_node;
	    
	}

};