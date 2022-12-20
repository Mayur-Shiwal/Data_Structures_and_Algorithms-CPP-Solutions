//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) 
            if (s[l++] != s[r--])
                return false;

        return true;
    }
    // Function to check if a palindrome pair exists
    bool palindromepair(int n, string words[]) {
        // code here
        // vector<vector<int>> res;
        unordered_map<string, int> mp;
        set<int> mySet;

        for (int i = 0; i <n; i++) {
            mp[words[i]] = i;
            mySet.insert(words[i].size());
        }
        
        for (int i = 0; i < n; i++) {
            string s = words[i];
            int len = s.size();
            reverse(s.begin(), s.end());
        
            if (mp.count(s) && mp[s] != i) {
                return true;
            }
        
            auto a = mySet.find(len);
            for (auto it = mySet.begin(); it != a; it++) {
                int d = *it;
                if (isPalindrome(s, 0, len - d - 1) && mp.count(s.substr(len - d))) {
                    return true;
                }
                if (isPalindrome(s, d, len - 1) && mp.count(s.substr(0, d))) {
                    return true;
                }
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends