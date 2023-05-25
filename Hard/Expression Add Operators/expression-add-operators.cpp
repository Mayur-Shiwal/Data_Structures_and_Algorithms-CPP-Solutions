//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(int ind, int &t, string &s, vector<string> &ans, int totalVal, int prev, string newString){
        if(ind == s.length()){
            if(totalVal == t) ans.push_back(newString);
            return;
        }
        string temp = "";
        int n = 0;
        for(int i=ind;i<s.length();i++){
            temp += s[i];
            n = n*10+(s[i] - '0');
            if(ind == 0) f(i+1, t, s, ans, n, n, temp);   
            else{
                f(i+1, t, s, ans, totalVal + n, n, newString + "+" + temp);
                f(i+1, t, s, ans, totalVal - n, -n, newString + "-" + temp);
                f(i+1, t, s, ans, totalVal - prev + prev * n, prev*n, newString + "*" + temp);
            }
            if(s[ind] == '0') break;
        }
        
    }
    vector<string> addOperators(string S, int target) {
        // code here
        vector<string> ans;
        f(0, target, S, ans, 0, 0, "");
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends