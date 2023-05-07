//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string s = "";
        s += str[0];
        for(int i=1;i<str.length();i++){
            if(str[i] < s[i-1]) s += str[i];
            else if(str[i] == s[i-1] && i != 1) s += str[i];
            else break;
        }
        string temp = s;
        reverse(temp.begin(), temp.end());
        s += temp;
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends