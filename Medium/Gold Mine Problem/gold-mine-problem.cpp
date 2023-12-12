//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dfs(int i, int j, int n, int m, vector<vector<int>> &v, vector<vector<int>> &dp){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int upDia = v[i][j] + dfs(i-1, j+1, n, m, v, dp);
        int right = v[i][j] + dfs(i, j+1, n, m, v, dp);
        int downDia = v[i][j] + dfs(i+1, j+1, n, m, v, dp);
        return dp[i][j] = max({upDia, right, downDia});
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, dfs(i, 0, n, m, M, dp));
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends