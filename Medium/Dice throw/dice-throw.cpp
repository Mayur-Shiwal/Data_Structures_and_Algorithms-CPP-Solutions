//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    long long f(int temp, int n, int m, int target, vector<vector<long long>> &dp){
        if(n == 0){
            if(temp == target) return 1;
            return 0;
        }
        if(dp[n][temp] != -1) return dp[n][temp];
        long long ans = 0;
        for(int i=1;i<=m;i++){
            temp += i;
            ans += f(temp, n-1, m, target, dp);
            temp -= i;
        }
        return dp[n][temp] = ans;
    }
    public:
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>> dp(N+1, vector<long long>((M*N)+1, -1));
        return f(0, N, M, X, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends