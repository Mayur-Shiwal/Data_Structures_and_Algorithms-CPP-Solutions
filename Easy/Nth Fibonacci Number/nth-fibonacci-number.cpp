//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int mod = 1e9 + 7;
        if(n == 1 || n == 2) return 1;
        int ans = 0;
        int x = 1, y = 1;
        for(int i=3;i<=n;i++){
            int temp = (x + y)%mod;
            x = y;
            y = temp;
            if(i == n) ans = temp;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends