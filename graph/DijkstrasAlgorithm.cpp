// shortest distance (path) from source to destination
// shortest path from source to all other vertices


// Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
// (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other 
// vertices (including source vertex also) using Dijkstra's Algorithm

#include<bits/stdc++.h>
using namespace std;
int getMinVertex(int * distance,bool * visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&((minVertex==-1)||distance[i]<distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
void Dijkstras(int ** edges ,int n){
    bool * visited = new bool[n]();
    int  * distance =  new int[n]();

    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex =  getMinVertex(distance,visited,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(!visited[j]&&edges[minVertex][j]!=0){
                int currD = distance[minVertex] + edges[minVertex][j];
                if(distance[j]>currD){
                    distance[j] =  currD;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int ** edges =  new int *[n];
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
        edges[s][f] = w;
    }
    Dijkstras(edges,n);
    return 0;
}