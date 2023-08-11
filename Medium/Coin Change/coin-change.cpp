//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
  private:
    ll int f(int ind, int n, int sum, int coins[], vector<vector<ll int>> &dp){
        if(sum == 0) return 1;
        if(ind == n) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        ll int notTake = f(ind+1, n, sum, coins, dp);
        ll int take = (coins[ind] <= sum) ? f(ind, n, sum - coins[ind], coins, dp) : 0;
        return dp[ind][sum] = notTake + take;
    }
  public:
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<ll int>> dp(N, vector<ll int>(sum+1, -1));
        return f(0, N, sum, coins, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends