//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long f(int ind, int prev, int n, vector<int> &arr, vector<vector<long long>> &dp){
        if(ind >= n) return 0;
        if(dp[ind][prev] != -1e12) return dp[ind][prev];
        long long ans = arr[ind] + f(ind+1, 1, n, arr, dp);
        if(prev) ans = max(ans, f(ind+1, 0, n, arr, dp));
        return dp[ind][prev] = ans;
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>> dp(N+1, vector<long long>(2, -1e12));
        return f(0, 1, N, A, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends