//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        long long ans = 0;
        stringstream ss(sentence);
        string temp = "";
        while(getline(ss, temp, ' ')){
            bool flag = false;
            for(int i=0;i<temp.length();i++){
                if(temp[i] == '9'){
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            else{
                bool flag = false;
                for(auto it: temp){
                    if(!isdigit(it)){
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                else{
                    long long n = stol(temp);
                    ans = max(ans, n);
                }
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends