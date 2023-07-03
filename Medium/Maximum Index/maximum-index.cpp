//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
private:
    // int ans = 0;
    // int f(int i, int j, int arr[], vector<vector<int>> &dp){
    //     if(i > j) return 0;
    //     if(arr[i] <= arr[j]){
    //         ans = max(ans, j-i);
    //         return ans;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     ans = max({ans, f(i+1, j,  arr, dp), f(i, j-1, arr, dp)});
    //     return  dp[i][j] = ans;
    // }
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return f(0, n-1, arr, dp);
        
        vector<int> left(n);
        vector<int> right(n);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            left[i] = min(left[i-1], arr[i]);
            right[n-i-1] = max(right[n-i], arr[n-i-1]);
        }
        int i=0, j=0;
        int ans = 0;
        while(j < n){
            if(left[i] <= right[j]){
                ans = max(ans, j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends