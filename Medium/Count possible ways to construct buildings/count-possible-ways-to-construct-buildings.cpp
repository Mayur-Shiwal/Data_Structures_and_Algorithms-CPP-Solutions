//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    const int mod = 1e9+7;
    int f(int n, vector<int> &dp){
        if(n == 1) return 2;
        if(n == 2) return 3;
        if(dp[n] != -1) return dp[n];
        int res = (f(n-1, dp) + f(n-2, dp));
        return dp[n] = res % mod;
    }
	public:
	int TotalWays(int N)
	{
	    // Code here
	    vector<int> dp(N+1, -1);
	    long long int ans = f(N, dp);
	    return (ans * ans)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends