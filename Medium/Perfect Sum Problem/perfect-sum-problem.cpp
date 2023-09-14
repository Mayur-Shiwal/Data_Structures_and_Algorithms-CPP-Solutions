//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = 1e9 + 7;
	int perfectSum(int arr[], int n, int tar)
	{
	    
        vector<vector<int>> dp(n+1, vector<int>(tar+1, 0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int sum=0;sum<=tar;sum++){
                if(arr[i-1]<=sum) {
                    int notTake = dp[i-1][sum];
                    int take = dp[i-1][sum-arr[i-1]];
                    dp[i][sum] = (take + notTake)%mod;
                }
                else {
                    dp[i][sum] = dp[i-1][sum]%mod;
                }
            }
        }
        return dp[n][tar];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends