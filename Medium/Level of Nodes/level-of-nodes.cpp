//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    if(X == 0) return 0;
	    vector<int> vis(V, 0);
	    queue<pair<int, int>> q;
	    q.push({0, 0});
	    vis[0] = 1;
	    while(!q.empty()){
	        auto frontEle = q.front(); q.pop();
	        int currEle = frontEle.first;
	        int level = frontEle.second;
	        if(currEle == X) return frontEle.second;
	        for(auto it: adj[currEle]){
	            if(!vis[it]){
	                vis[it] = 1;
	                q.push({it, level+1});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends