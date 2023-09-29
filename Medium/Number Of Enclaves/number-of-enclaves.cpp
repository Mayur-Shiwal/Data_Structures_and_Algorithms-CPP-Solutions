//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        queue<pair<int, int>> q;
        int vis[grid.size()][grid[0].size()] = {0};
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(abs(delrow) == abs(delcol)) continue;
                    int nrow = delrow + row;
                    int ncol = delcol + col;
                    if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        q.push({nrow, ncol});                    
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends