//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    #define ll long long
    const ll mod = 1e9+7;
    ll f(int n, int &k, vector<ll> &dp){
        if(n == 1) return k;
        if(n == 2) return static_cast<long long>(k)*k;
        if(dp[n] != -1) return dp[n];
        ll same = (f(n-2, k, dp)*(k-1))%mod;
        ll diff = (f(n-1, k, dp)*(k-1))%mod;
        return dp[n] = (same + diff)%mod;
    }
    // ll f(int firstColor, int secondColor, int n, int k, vector<vector<vector<ll>>> &dp){
    //     if(n == 0) return 1;
    //     if(dp[n][firstColor][secondColor] != -1) return dp[n][firstColor][secondColor];
    //     ll cnt = 0;
    //     for(int i=1;i<=k;i++){
    //         if(i == firstColor && firstColor == secondColor) continue;
    //         cnt = (cnt + f(i, firstColor, n-1, k, dp))%mod; 
    //     }
    //     return dp[n][firstColor][secondColor] = cnt;
    // }
    public:
    long long countWays(int n, int k){
        // code here
        // vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(k+1, -1)));
        // return f(0, 0, n, k, dp);
        vector<ll> dp(n+1, -1);
        return f(n, k, dp)%mod;
    }
};


//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends