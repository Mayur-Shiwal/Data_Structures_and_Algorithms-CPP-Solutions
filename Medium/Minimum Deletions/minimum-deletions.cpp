//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
private:
    int lcs(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(m == 0 || n == 0) return 0;
        if(s1[n-1] == s2[m-1]) return 1 + lcs(n-1, m-1, s1, s2, dp);
        if(dp[n][m] != -1) return dp[n][m];
        int n1 = lcs(n-1, m, s1, s2, dp);
        int m1 = lcs(n, m-1, s1, s2, dp);
        return dp[n][m] = max(n1, m1);
    }
public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.length();
        string s2 = S;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = lcs(n, n, S, s2, dp);
        return n - ans;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends