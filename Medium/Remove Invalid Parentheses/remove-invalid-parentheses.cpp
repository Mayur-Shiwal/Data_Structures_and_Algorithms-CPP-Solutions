//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int invalidParenthesis(string s){
        stack<char> st;
        int i=0;
        while(i < s.size()){
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')'){
                if(st.size() > 0 && st.top() == '(') st.pop();
                else st.push(')');
            }
            i++;
        }
        return st.size();
    }
    void solve(string s, int invalidPar, vector<string> &ans, unordered_map<string, int> &mp){
        if(mp[s] != 0) return;
        else mp[s]++;
        if(invalidPar < 0) return;
        if(invalidPar == 0){
            if(!invalidParenthesis(s)) ans.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++){
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            solve(left+right, invalidPar-1, ans, mp);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        // code here
        vector<string> ans;
        unordered_map<string, int> mp;
        solve(s, invalidParenthesis(s), ans, mp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends