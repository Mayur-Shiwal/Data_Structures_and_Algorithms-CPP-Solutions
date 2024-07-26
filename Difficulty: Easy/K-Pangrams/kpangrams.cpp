//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int n = 0;
        vector<bool> v(26, false);
        for(auto it: str){
            if(it == ' ') continue;
            v[it - 'a'] = true;
            n++;
        }
        if(n < 26) return false;
        for(auto it: v){
            if(it == false) k--;
        }
        return k >= 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends