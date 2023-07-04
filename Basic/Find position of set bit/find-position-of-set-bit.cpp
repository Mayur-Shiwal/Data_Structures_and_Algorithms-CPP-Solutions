//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N == 0) return -1;
        string s = bitset<32>(N).to_string();
        reverse(s.begin(), s.end());
        int cnt = 0;
        int i;
        int ind = 0;
        for(i=0;i<s.length();i++){
            if(s[i] == '1' && cnt == 0){
                ind = i+1;
                cnt++;
            } 
            else if(s[i] == '1' && cnt > 0) return -1;
        }
        return ind;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends