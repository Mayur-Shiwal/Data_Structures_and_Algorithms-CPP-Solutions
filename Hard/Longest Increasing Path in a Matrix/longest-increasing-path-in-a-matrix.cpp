//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=mat.size() || j >= mat[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int currMaxi = 1;
        if(i+1 < mat.size() && i+1 >= 0 && mat[i+1][j] > mat[i][j]){
            currMaxi = max(currMaxi, 1 + f(mat, i+1, j, dp));
        }
        if(j+1 < mat[0].size() && j+1 >= 0 && mat[i][j+1] > mat[i][j]){
            currMaxi = max(currMaxi, 1 + f(mat, i, j+1, dp));
        }
        if(i-1 < mat.size() && i-1 >= 0 && mat[i-1][j] > mat[i][j]){
            currMaxi = max(currMaxi, 1 + f(mat, i-1, j, dp));
        }
        if(j-1 < mat[0].size() && j-1 >= 0 && mat[i][j-1] > mat[i][j]){
            currMaxi = max(currMaxi, 1 + f(mat, i, j-1, dp));
        }
        return dp[i][j] = currMaxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        // Code herev
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi, f(matrix, i, j, dp));
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends