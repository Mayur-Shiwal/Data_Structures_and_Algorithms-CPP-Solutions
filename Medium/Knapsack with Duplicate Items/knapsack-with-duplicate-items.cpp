//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i, int W, int val[], int wt[], vector<vector<int>> &dp){
        if(i == 0) return ((W/wt[0]) * val[0]);
        if(dp[i][W] != -1) return dp[i][W];
        int notTake = 0 + f(i-1, W, val, wt, dp);
        int take = INT_MIN;
        if(wt[i]<=W) take = val[i] + f(i, W - wt[i], val, wt, dp);
        return dp[i][W] = max(take, notTake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W+1, -1));
        return f(N-1, W, val, wt, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends