//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int LongestRepeatingSubsequence(string str){
	    // Code here
	    vector<vector<int>> dp(str.length()+1, vector<int>(str.length()+1, 0));
	    for(int i=1;i<=str.length();i++){
	        for(int j=1;j<=str.length();j++){
	            if(str[i-1] == str[j-1] && i != j) dp[i][j] = dp[i-1][j-1] + 1;
	            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    return dp[str.length()][str.length()];
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
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends