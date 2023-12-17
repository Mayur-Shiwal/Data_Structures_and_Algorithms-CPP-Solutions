//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1) return arr[0];
        vector<int>dp(n+1,0);
        dp[n-1]=arr[n-1];
        dp[n-2]=arr[n-2];
        int maxsum=max(arr[n-2],arr[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i]=arr[i]+ max(dp[i+2],dp[i+3]);
            maxsum=max(maxsum,dp[i]);
        }
        return maxsum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends