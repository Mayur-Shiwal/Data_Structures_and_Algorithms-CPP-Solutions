//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int atmost_k_chars(string &s, int k) {
        if (s.size() == 0) {
            return 0;
        }
        vector<int>m(26,0);
        int ans = 0, left = 0;
        int distinct_chars=0;//distinct chars size of current window
        for (int i = 0; i < s.size(); i++) {
             m[s[i]-'a']++;
             
             if(m[s[i]-'a']==1) distinct_chars++;//first time count in size
            while (distinct_chars > k) {
                m[s[left]-'a']--;
                if (m[s[left]-'a'] == 0) {
                    distinct_chars--;
                }
                left++;
            }
            ans += (i - left + 1);
        }
        return ans;
    }

    long long int substrCount (string s, int k) {
        return atmost_k_chars(s,k)-atmost_k_chars(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends