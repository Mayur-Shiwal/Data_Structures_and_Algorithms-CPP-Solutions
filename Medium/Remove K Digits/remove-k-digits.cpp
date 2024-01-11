//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            while(!st.empty() && st.top() > s[i] && k > 0) {
                st.pop();
                k--;
            };
            st.push(s[i]);
        }
        while(k--) st.pop();
        if(st.size() == 0) return "0";
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while(ans[i] == '0') i++;
        return (i == ans.size()) ? "0" : ans.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends