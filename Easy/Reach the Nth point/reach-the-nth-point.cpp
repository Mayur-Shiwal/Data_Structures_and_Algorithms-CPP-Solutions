//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    const int mod = 1e9+7;
        int f(int n, vector<int> &dp) {
            if(n == 1) return 1;
            if(n == 2) return 2;
            if(dp[n] != -1) return dp[n];
            int step1 = f(n-1, dp);
            int step2 = f(n-2, dp);
            return dp[n] = (step1 + step2) % mod;
        }
	public:
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n+1, -1);
		    return f(n, dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends