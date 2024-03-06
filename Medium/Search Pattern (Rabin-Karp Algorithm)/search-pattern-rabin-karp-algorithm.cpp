//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector <int> search(string pattern, string text){
        //code here.
        int i = 0, j = 0;
        int n = pattern.length();
        int m = text.length();
        vector<int> ans;
        for(int i=0;i<m-n+1;i++){
            if(text.substr(i, n) == pattern) ans.push_back(i+1);
        }
        return ans;
    }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends