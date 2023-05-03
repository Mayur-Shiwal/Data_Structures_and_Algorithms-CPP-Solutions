//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        set<string> st;
        for(int i=0;i<arr.size();i++){
            string temp = arr[i];
            st.insert(temp);
        }
        if(st.size() < n) return false;
        for(int i=0;i<arr.size();i++){
            string temp = arr[i];
            reverse(temp.begin(), temp.end());
            if(st.find(temp) == st.end()) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends