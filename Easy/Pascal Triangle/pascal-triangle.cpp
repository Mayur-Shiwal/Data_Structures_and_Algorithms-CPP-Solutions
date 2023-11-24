//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution{
public:
    int M=1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<ll>> m(n);
        // int arr[n][n];
        for(int i=0; i<n; i++)
        {
            m[i].resize(i+1);
            m[i][0] = m[i][i] = 1;
            for(int j=1; j<i; j++)
            {
                m[i][j] = (m[i-1][j-1]%M + m[i-1][j]%M)%M;
                // arr[n][n] = m[i][j];
            }     
        }
        return m[n-1];
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends