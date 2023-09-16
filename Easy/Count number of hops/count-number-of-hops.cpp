//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution
{
    public:
    int mod = 1000000007;
    ll f(int ind, int n, vector<int> &dp){
        if(ind == n) return 1;
        if(ind > n) return 0;
        if(dp[ind] != -1) return dp[ind];
        ll ans = 0;
        ans = (f(ind+1, n, dp) + f(ind+2, n, dp) + f(ind+3, n, dp))%mod;
        return dp[ind] = ans;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        vector<int> dp(n+1, -1);
        return f(0, n, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends