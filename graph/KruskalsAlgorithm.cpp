// Kruskal's Algorithm
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices
//  (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.


//  KRUSKAL'S ALGORITHM //

// we will start selecting edges from minimum weight in increasing order of weight
// if there is no path exist between vertices v1 and v2 we can add the edge v1-v2 into MST
// if there is already a path we will skip this edge
// we will add total n-1 edge in this way and the output will be our MST edges 

// if a vertex v1 and v2 lies in differnet component then we can add an edge v1-v2 . else we can't add them.


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Edge{
    public :
    ll src;
    ll des;
    ll weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}
ll getParent(ll v,ll * parent){
    if(parent[v]==v){
        return v;
    }
    return getParent(parent[v],parent);
}
Edge * Kruskals( Edge * edges,ll n,ll E){
    // sort the edges array in increaing order
    sort(edges,edges+E,compare);
    Edge * output =  new Edge[E-1];
    ll* parent =  new ll [n];
    for(ll i=0;i<n;i++){
        parent[i] =i;
    }
    ll count =0;
    ll i=0;
    while(count<(n-1)){
        // check the topmost parent of v1 and v2 . v1 and v2 are the vertices of current edge
        Edge currEdge = edges[i];
        int srcParent = getParent(currEdge.src,parent);
        int desParent = getParent(currEdge.des,parent);
        if(srcParent!=desParent){
            output[count]= currEdge;
            count++;
            parent[srcParent] =desParent;
        }
            i++;
    }
        return output;
}
int main(){
    ll n,E;
    cin>>n>>E;
    Edge * edges = new Edge[E];
    for(ll i=0;i<E;i++){
        cin>>edges[i].src>>edges[i].des>>edges[i].weight;
    }
    Edge * output = Kruskals(edges,n,E);
    for(ll i=0;i<n-1;i++){
        if(output[i].src<output[i].des)
        cout<<output[i].src<<" "<<output[i].des<<" "<<output[i].weight<<endl;
        else
          cout<<output[i].des<<" "<<output[i].src<<" "<<output[i].weight<<endl;
    }
    return 0;
}