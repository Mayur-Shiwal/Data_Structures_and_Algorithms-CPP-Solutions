//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V, 0);
	    int ans = -1;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i, adj, vis);
	            ans = i;
	        }
	    }
	    vis.assign(V, 0);
	    dfs(ans, adj, vis);
	    for(int i=0;i<V;i++){
	        if(!vis[i]) return -1;
	    }
	    return ans;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends