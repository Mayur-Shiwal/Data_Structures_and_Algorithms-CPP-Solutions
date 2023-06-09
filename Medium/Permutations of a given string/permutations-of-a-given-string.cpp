//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void f(int ind, string &s, vector<string> &ans, unordered_map<string, int> &mp){
            if(ind >= s.length()){
                if(mp.find(s) == mp.end()){
                    ans.push_back(s);
                    mp[s]++;
                }
                return;
            }
            for(int i=ind;i<s.length();i++){
                swap(s[ind], s[i]);
                f(ind+1, s, ans, mp);
                swap(s[ind], s[i]);
            }
            return;
        }
	public:
		vector<string>find_permutation(string S)
		{
		  //approach 1 using STL
		  //  sort(S.begin(), S.end());
		  //  vector<string> ans;
		  //  ans.push_back(S);
		  //  while(next_permutation(S.begin(), S.end())) ans.push_back(S);
		  //  return ans;
		  
		  //approach 2
		  vector<string> ans;
		  unordered_map<string, int> mp;
		  f(0, S, ans, mp);
		  sort(ans.begin(), ans.end());
		  return ans;
		}
};
//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
