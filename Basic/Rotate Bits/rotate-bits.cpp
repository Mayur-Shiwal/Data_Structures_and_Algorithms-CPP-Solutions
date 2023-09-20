//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    vector <int> rotate (int n, int d){
        //code here.
        vector<int> ans(2, 0);
        d %= 16;
        ans[0] = ((n << d) | (n >> (16 - d))) & 0xFFFF;
        ans[1] = ((n >> d) | (n << (16 - d))) & 0xFFFF;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends