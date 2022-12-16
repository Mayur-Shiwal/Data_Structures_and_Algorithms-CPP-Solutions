//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            int row = frontNode[0];
            int col = frontNode[1];
            if(row < 0 || row >= n || col < 0 || col >= m) continue;
            if(row == n-1 && col == m-1) return frontNode[2];
            if(mat[row][col] == 1){
                if(frontNode[3] > 0) frontNode[3]--;
                else continue;
            }
            if(vis[row][col] != -1 && vis[row][col] >= frontNode[3]) continue;
            vis[row][col] = frontNode[3];
            q.push({row+1, col, frontNode[2]+1, frontNode[3]});
            q.push({row, col-1, frontNode[2]+1, frontNode[3]});
            q.push({row-1, col, frontNode[2]+1, frontNode[3]});
            q.push({row, col+1, frontNode[2]+1, frontNode[3]});
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends