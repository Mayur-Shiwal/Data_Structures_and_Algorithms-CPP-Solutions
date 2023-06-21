//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int sumOfNaturals(int n) {
        // code here
        int mod = 1e9+7;
        // int totalSum = 0;
        // for(int i=1;i<=n;i++) totalSum = (totalSum + i)%mod;
        // return totalSum%mod;
        long long ans = (long long)n * (long long)(n+1);
        ans /= 2;
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends