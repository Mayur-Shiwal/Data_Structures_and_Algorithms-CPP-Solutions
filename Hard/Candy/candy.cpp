//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &ratings) {
        // code here
        if(n < 2) return n;
        vector<int> candies(n, 1);
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1] > ratings[i]) candies[i-1] = max(candies[i]+1, candies[i-1]);
        }
        int ans = 0;
        for(auto it: candies) ans += it;
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

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends