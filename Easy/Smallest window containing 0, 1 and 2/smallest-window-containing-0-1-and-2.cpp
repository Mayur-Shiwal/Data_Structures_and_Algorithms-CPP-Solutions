//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int zero=-1,one=-1,two=-1,ans=INT_MAX;
        int mini,maxi;
        for(int i=0;i<S.length();i++) {
            if(S[i]=='0') zero=i;
            else if(S[i]=='1') one=i;
            else if(S[i]=='2') two=i;
            if(zero!=-1 && one!=-1 && two!=-1) {
                mini=min(zero,min(one,two));
                maxi=max(zero,max(one,two));
                ans=min(ans,(maxi-mini+1));
            }
        }
        if(ans!=INT_MAX) {
            return ans;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends