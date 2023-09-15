//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int i, int target, int arr[], vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i == 0) return (arr[0] == target);
        if(dp[i][target] != -1) return dp[i][target];
        bool notTake = f(i-1, target, arr, dp);
        bool take = false;
        if(arr[i] <= target) take = f(i-1, target - arr[i], arr, dp);
        return dp[i][target] = take | notTake;
    }

    bool solve(int n, int k, int arr[]){
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n-1, k, arr, dp);
    }

    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i=0;i<N;i++) totalSum += arr[i];
        if(totalSum % 2) return false;
        int target = totalSum/2;
        bool temp = solve(N, target, arr);
        if(temp) return 1;
        else return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends