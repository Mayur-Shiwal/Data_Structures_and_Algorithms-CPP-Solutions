//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int f(int i, int n, int price[], vector<vector<int>> &dp){
      if(i == 0) return (n * price[0]);
      if(dp[i][n] != -1) return dp[i][n];
      int notTake = 0 + f(i-1, n, price, dp);
      int take = INT_MIN;
      int rodLength = i+1;
      if(rodLength<= n) take = price[i] + f(i, n - rodLength, price, dp);
      return dp[i][n] = max(take, notTake);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, n, price, dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends