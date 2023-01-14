//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans = "";
        int i = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] == '.') i++;
            if(i==s.size()) break;
            int j = i+1;
            while(j < s.length() && s[j] != '.') j++;
            string temp = s.substr(i, j-i);
            ans = (ans.length() == 0) ? ans = temp : temp + "." + ans;
            i = j+1;
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends