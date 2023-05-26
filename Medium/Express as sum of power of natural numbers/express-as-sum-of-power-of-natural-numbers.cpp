//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1e9+7;
    int f(int n, int x, int ind, int maxLimit, vector<vector<long long>> &dp){
        if(n == 0) return 1;
        if(ind > maxLimit || n < 0) return 0;
        if(dp[n][ind] != -1) return dp[n][ind];
        long long int t = pow(ind, x);
        int take = f(n-t, x, ind+1, maxLimit, dp);
        int notTake = f(n, x, ind+1, maxLimit, dp);
        return dp[n][ind] = (take + notTake)%mod;
        
    }
    int numOfWays(int n, int x)
    {
        // code here
        int maxLimit = pow(n, 1.0/x);
        vector<vector<long long>> dp(n+1, vector<long long>(maxLimit+1, -1));
        return f(n, x, 1, maxLimit, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends