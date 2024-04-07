//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int f(int i, int j, int a[], int b[], vector<vector<int>> &dp){
        if(j < 0) return 0;
        if(i < 0) return INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        int take = a[i] * b[j] + f(i-1, j-1, a, b, dp);
        int notTake = f(i-1, j, a, b, dp);
        return dp[i][j] = max(take, notTake);
    }
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
		return f(n-1, m-1, a, b, dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends