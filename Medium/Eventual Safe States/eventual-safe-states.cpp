//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int checkNodes[]){
        vis[node] = 1;
        pathVis[node] = 1;
        checkNodes[node] = 0;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis, checkNodes) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        checkNodes[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int checkNodes[V] = {0};
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis, checkNodes);
            }
        }
        for(int i=0;i<V;i++){
            if(checkNodes[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends