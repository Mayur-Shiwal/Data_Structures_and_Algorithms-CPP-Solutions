//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int ans = 0;
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         if(i == j) continue;
        //         else if(arr[i] % arr[j] == 0){
        //             ans++;
        //             break;
        //         }
        //     }
        // }
        // return ans;
        int maxiElement = -1e9;
        for(auto it: arr) maxiElement = max(maxiElement, it);
        vector<int> v(maxiElement+1, 0);
        for(int i=0;i<N;i++){
            int s = arr[i];
            if(v[s] <= 1){
                for(int j=s;j<v.size();j=j+s) v[j]++;
            }
        }
        for(int i=0;i<N;i++){
            if(v[arr[i]] > 1) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
