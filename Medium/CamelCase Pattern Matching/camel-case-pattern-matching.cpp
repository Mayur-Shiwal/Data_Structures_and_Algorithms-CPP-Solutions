//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> ans;
        for(auto it: Dictionary){
            int cnt = 0;
            for(int i=0;i<it.length();i++){
                if(it[i] >= 'A' && it[i] <= 'Z'){
                    if(it[i] != Pattern[cnt++]) break;
                    if(cnt == Pattern.length()){
                        ans.push_back(it);
                        break;
                    }
                }
            }
        }
        if(!ans.size()) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends