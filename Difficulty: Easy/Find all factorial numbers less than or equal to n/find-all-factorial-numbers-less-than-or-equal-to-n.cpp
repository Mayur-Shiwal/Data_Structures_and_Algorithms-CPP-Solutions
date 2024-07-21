//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
    private:
    ll f(ll n){
        if(n == 1) return 1;
        return n * f(n-1);
    }
    public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<ll> ans;
        ll ind = 1;
        ll val = 1;
        while(val <= n){
            val = f(ind++);
            if(val <= n) ans.push_back(val);
            else break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends