//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void f(int ind, string &s, unordered_set<string> &st, int n, string temp, vector<string> &ans){
        if(ind == n) {
            temp = temp.substr(1);
            ans.push_back(temp);
            return;
        }
        string res = "";
        for(int i=ind;i<n;i++){
            res += s[i];
            if(st.find(res) != st.end()) f(i+1, s, st, n, temp + " " + res, ans);
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> ans;
        // for(string it: dict){
        //     if(s.substr(0, it.length()) == it){
        //         if(it.length() == s.length()) ans.push_back(it);
        //         else{
        //             vector<string> temp = wordBreak(n, dict, s.substr(it.length()));
        //             for(string str: temp) ans.push_back(it + " " + str);
        //         }
        //     }
        // }
        // return ans;
        unordered_set<string> st(dict.begin(), dict.end());
        string temp = "";
        f(0, s, st, s.length(), temp, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends