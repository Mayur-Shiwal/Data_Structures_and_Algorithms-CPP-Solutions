//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans = "";
            string temp = "";
            for(int i=0;i<s.length();i++){
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                    ans = s[i] + temp + ans;
                    temp = "";
                }
                else temp += s[i];
            }
            if(temp.length() > 0) ans = temp + ans;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends