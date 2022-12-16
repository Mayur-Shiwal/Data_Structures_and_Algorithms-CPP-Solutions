//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int ans = INT_MAX;
    int f(int s1, int s2, int i, int arr[], int n, vector<vector<int>> &dp){
        if(i == n) return ans = min(ans, abs(s1 - s2));
        if(dp[i][s1] != -1) return dp[i][s1];
        int take = INT_MAX;
        int notTake = INT_MAX;
        take = f(s1 + arr[i], s2 - arr[i], i+1, arr, n, dp);
        notTake = f(s1, s2, i+1, arr, n, dp);
        return dp[i][s1] = min(take, notTake);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum = 0;
	    for(int i=0;i<n;i++) totalSum += arr[i];
	    vector<vector<int>> dp(n+1, vector<int> (totalSum+1, -1));
	    return f(0, totalSum, 0, arr, n, dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends