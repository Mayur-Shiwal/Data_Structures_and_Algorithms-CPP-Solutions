//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    const int mod = 1e9+7;
        int f(int i, string s, vector<int> &dp){
            if(i >= s.length()) return 1;
            if(dp[i] != -1) return dp[i];
            int ans = 0;
            int sd = s[i] - '0', dd = 0;
            if(i < s.length()-1) dd = (sd*10 + s[i+1] - '0')%mod;
            if(sd > 0) ans = (ans + f(i+1, s, dp))%mod;
            if(sd > 0 && dd > 0 && dd <= 26) ans = (ans + f(i+2, s, dp))%mod;
            return dp[i] = ans;
        }
	public:
		int CountWays(string str){
		    // Code here
		    vector<int> dp(str.length()+1, -1);
		    return f(0, str, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends