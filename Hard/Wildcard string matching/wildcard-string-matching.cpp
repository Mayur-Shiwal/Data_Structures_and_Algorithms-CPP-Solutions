//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    private:
    bool f(int i, int j, string s1, string s2){
        if(i < 0 && j < 0) return 1;
        if(i < 0 && j >= 0) return false;
        if(i >= 0 && j < 0){
            for(int k=0;k<=i;k++){
                if(s1[k] != '*') return false;
            }
            return true;
        }
        if(s1[i] == s2[j] || s1[i] == '?') return f(i-1, j-1, s1, s2);
        else if(s1[i] == '*') return f(i-1, j, s1, s2) || f(i, j-1, s1, s2);
        return false;
    }
    public:
    bool match(string wild, string pattern)
    {
        // code here
        vector<vector<int>> 
        int n = wild.size(), m = pattern.size();
        return f(n-1, m-1, wild, pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends