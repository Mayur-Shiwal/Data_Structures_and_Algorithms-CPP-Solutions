//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int ans = INT_MIN, temp = 0, last = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            temp += a[i];
            if(i-j+1 == k) ans = max(ans, temp);
            else if(i-j+1 > k){
                last += a[j++];
                if(last <= 0){
                    temp -= last;
                    last = 0;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends