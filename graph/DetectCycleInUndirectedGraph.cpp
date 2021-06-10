#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool dfs(int n, vector<int> adj[],int sv,int parent,bool * visited){
        visited[sv] = true;
        for(int i : adj[sv]){
            if(!visited[i]){
               if(dfs(n,adj,i,sv,visited)){
                   return true;
               }
            }else if(i!=parent){
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){   
	    int n = V;
	    bool * visited =  new bool[n];
	    for(int i =0;i<n;i++){
	        visited[i] = false;
	    }
	    for(int i =0;i<n;i++){
	        if(!visited[i]){
	            if(dfs(n,adj,i,-1,visited))
	                return true;
	        }
	    }
	    return false;
	}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 