//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string A){
	    // Code here
	    unordered_map<char, int> mp;
	    string ans = "";
	    queue<char> q;
	    for(auto it: A){
	        mp[it]++;
	        if(mp[it] == 1) q.push(it);
	        while(!q.empty() && mp[q.front()] > 1) q.pop();
	        ans += (q.empty()) ? '#' : q.front();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends