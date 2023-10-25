//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int i, int w, int n, int val[], int wt[], vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        int notTake = f(i+1, w, n, val, wt, dp);
        int take = 0;
        if(wt[i] <= w) take = val[i] + f(i, w-wt[i], n, val, wt, dp);
        return dp[i][w] = max(take, notTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        return f(0, W, N, val, wt, dp);
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
