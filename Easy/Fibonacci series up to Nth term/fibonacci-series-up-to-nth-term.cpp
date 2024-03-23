//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    int f(vector<int> &dp, int n, int i, vector<int> &ans){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int lastDigit = f(dp, n, i-1, ans);
        int secondLastDigit = f(dp, n, i-2, ans);
        dp[i] = (lastDigit + secondLastDigit) % mod;
        ans.push_back(dp[i]);
        return f(dp, n, i+1, ans);
    }
    vector<int> Series(int n) {
        // Code here
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        f(dp, n, 2, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends