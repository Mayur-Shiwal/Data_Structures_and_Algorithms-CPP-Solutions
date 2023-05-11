//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    char help(string s){
        int i = 0;
        int j = s.length()-1;
        while(i <= j){
            if(s[i] != '?') return s[i];
            if(s[j] != '?') return s[j];
            i++;
            j--;
        }
        return '$';
    }
    public:
    int minimumSum(string s) {
        // code here
        int i = 0;
        int j = s.length()-1;
        int ans = 0;
        char prev = '$';
        while(i <= j){
            if(s[i] == '?' && s[j] == '?'){
                if(prev == '$'){
                    prev = help(s);
                    if(prev == '$') return 0;
                }
            }
            else if(s[i] == '?'){
                if(prev != '$') ans += 2*abs(prev - s[j]);
                prev = s[j];
            }
            else if(s[j] == '?'){
                if(prev != '$') ans += 2*abs(prev - s[i]);
                prev = s[i];
            }
            else if(s[i] == s[j]){
                if(prev != '$') ans += 2*abs(prev-s[i]);
                prev = s[i];
            }
            else return -1;
            i++;
            j--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends