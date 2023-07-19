//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    // int lcs(string s, string t){
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    //     for(int j=0;j<=m;j++) dp[0][j] = 0;
    //     for(int i=0;i<=n;i++) dp[i][0] = 0;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(s[i-1] == t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
    //             else dp[i][j] = max((dp[i-1][j]), dp[i][j-1]);
    //         }
    //     }
    //     return dp[n][m];
    // }
    int f(int i, int j, string s, vector<vector<int>> &dp){
        if(i == j) return 1;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) dp[i][j] = 2 + f(i+1, j-1, s, dp);
        else dp[i][j] = max(f(i+1, j, s, dp), f(i, j-1, s, dp));
        return dp[i][j];
    }
    int longestPalinSubseq(string A) {
        //code here
        // string B = A;
        // reverse(B.begin(), B.end());
        // return lcs(A, B);
        vector<vector<int>> dp(A.length(), vector<int>(A.length(), -1));
        return f(0, A.length()-1, A, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
