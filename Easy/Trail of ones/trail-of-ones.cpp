//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    const int mod = 1e9+7;
    int f(int n, int twoOnes, int flag, vector<vector<vector<int>>> &dp){
        if(n == 0) return flag ? 1 : 0;
        if(dp[n][twoOnes][flag] != -1) return dp[n][twoOnes][flag];
        int take = 0, skip = 0;
        if(twoOnes) take = f(n-1, 1, 1, dp);
        else take = f(n-1, 1, flag, dp);
        skip = f(n-1, 0, flag, dp);
        return dp[n][twoOnes][flag] = (take+skip)%mod;
    }
public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(n, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends