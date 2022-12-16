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
     bool isverify(int adjr,int adjc,int n)
    {
        return adjr>=0&&adjr<n&&adjc>=0&&adjc<n;
    }
    public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjoinSet ds(n*n);
       //step1
       for(int row=0;row<n;row++){
           for(int col=0;col<n;col++){
               if(grid[row][col]==0){
                   continue;
               }
               else{
                   int delrow[]={-1,0,1,0};
                   int delcol[]={0,-1,0,1};
                   for(int i=0;i<4;i++){
                       int adjr=row+delrow[i];
                       int adjc=col+delcol[i];
                       if(isverify(adjr,adjc,n)&&grid[adjr][adjc]==1){
                           int nrow=row*n+col;
                           int ncol=adjr*n+adjc;
                           ds.unionBySize(nrow,ncol);
                       }
                   }
               }
           }
       }
       //step2
       int mx=0;
       for(int row=0;row<n;row++){
           for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                   continue;
               }
               else{
                   int delrow[]={-1,0,1,0};
                   int delcol[]={0,-1,0,1};
                    set<int>sa;
                   for(int i=0;i<4;i++){
                       int adjr=row+delrow[i];
                       int adjc=col+delcol[i];
                       if(isverify(adjr,adjc,n)){
                           if(grid[adjr][adjc]==1){
                               sa.insert(ds.findUPar(adjr*n+adjc));
                           }
                       }
                  }
                  int size1=0;
                  for(auto it:sa){
                     size1+=ds.size[it]; 
                  }
                  mx=max(size1+1,mx);
                }
            }
           mx=max(mx,ds.size[ds.findUPar(n*n-1)]);
           /*
            for(int i=0;i<n*n;i++)
            {
                mx=max(mx,ds.size[ds.findUPar(i)]);
            }*/
        }
        return mx;
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