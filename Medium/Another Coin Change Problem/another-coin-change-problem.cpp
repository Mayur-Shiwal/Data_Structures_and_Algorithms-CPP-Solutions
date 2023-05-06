//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
private:
    bool f(vector<int> &coins, int sum, int take, int n, int k, int t, int i, vector<vector<int>> &dp){
        if(i >= n) return 0;
        if(sum > t || take > k) return 0;
        if(take == k){
            if(sum == t) return 1;
            return 0;
        }
        if(dp[sum][take] != -1) return dp[sum][take];
        return dp[sum][take] = f(coins, sum + coins[i], take + 1, n, k, t, i, dp) || f(coins, sum, take, n, k, t, i+1, dp);
    }
public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>> dp(target+1, vector<int>(K+1, -1));
        return f(coins, 0, 0, N, K, target, 0, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends