//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjoinSet{   
public:
    vector<int> rank, parent, size;
    DisjoinSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultimateParent_u = findUPar(u);
        int ultimateParent_v = findUPar(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(rank[ultimateParent_u] < rank[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
        }
        else if(rank[ultimateParent_v] < rank[ultimateParent_u]){
            parent[ultimateParent_v] = ultimateParent_u;
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ultimateParent_u = findUPar(u);
        int ultimateParent_v = findUPar(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(size[ultimateParent_u] < size[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }

};
class Solution {
private:
    bool isValid(int i, int j, int n){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjoinSet ds(n*n);
        //connecting components
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                for(int delrow=-1;delrow<=1;delrow++){
                    for(int delcol=-1;delcol<=1;delcol++){
                        if(abs(delrow) == abs(delcol)) continue;
                        int nrow = delrow + i;
                        int ncol = delcol + j;
                        if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                            int nodeNo = i * n + j;
                            int adjNodeNo = nrow * n + ncol;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        //finding maximum island
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) continue;
                set<int> st;
                for(int delrow=-1;delrow<=1;delrow++){
                    for(int delcol=-1;delcol<=1;delcol++){
                        if(abs(delrow) == abs(delcol)) continue;
                        int nrow = delrow + i;
                        int ncol = delcol + j;
                        if(isValid(nrow, ncol, n)){
                            if(grid[nrow][ncol] == 1){
                                st.insert(ds.findUPar(nrow * n + ncol));
                            }
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it: st) sizeTotal += ds.size[it];
                maxi = max(maxi, sizeTotal+1);
            }
        }
        for(int i=0;i<n*n;i++){
            maxi = max(maxi, ds.size[ds.findUPar(i)]);
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends