//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool f(int n,int coins[],int sum,vector<vector<int>> &dp){
        
        if(sum and (sum%20==0 or sum%24==0 or sum==2024)) return true;
        if(n<0) return false;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        // if any of the possibility comes true then no need to check other possibilities
        if(f(n-1,coins,sum+coins[n-1],dp)) return dp[n][sum] = true; //take
        if(f(n-1,coins,sum,dp)) return dp[n][sum] = true; //not take
        
        return dp[n][sum] = false;
    }
    int isPossible(int N , int coins[]) 
    {
        int sum=0;
        vector<vector<int>>dp(N+1,vector<int>(2025,-1));
        return f(N,coins,sum,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends