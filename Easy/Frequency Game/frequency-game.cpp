//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it: mp){
            if(it.second < mini){
                mini = it.second;
                maxi = it.first;
            }
            else if(it.second == mini){
                if(maxi < it.first) maxi = it.first;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends