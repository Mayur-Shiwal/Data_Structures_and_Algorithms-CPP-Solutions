//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int Find(int i,vector<int>&parent){
        if(i==parent[i]) return parent[i];
        return parent[i] = Find(parent[i],parent);
    }
    void Union(int x, int y, vector<int> &rank, vector<int> &parent) {
    int u = Find(x, parent);
    int v = Find(y, parent);
 
    if (u == v)
        return;
 
    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[v] > rank[u])
        parent[u] = v;
    else {
        parent[v] = u;
        rank[u]++;
    }
}
int detectCycle(int V, vector<int>adj[])
{
    // Code here
    vector<int> parent(V);
    vector<int> rank(V);
    
    for(int i=0;i<V;i++){
        parent[i] = i;
        rank[i] = 1;
    } 
    
    for(int i=0;i<V;i++){
        for(auto &x:adj[i]){
            if(i<x){
                int u_parent = Find(i,parent);
                int v_parent = Find(x,parent);
                if(u_parent==v_parent) return true;
                Union(u_parent,v_parent,rank,parent);
            }
        }
    }
    return false;
}
};


//{ Driver Code Starts.
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends