//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
        long long mod=1e9+7;
        long long arr[26]={0},pre=1,cur=1;
        for(int i=0;i<n;i++){
            cur=(pre*2)%mod;
            cur = (cur - arr[s[i] - 'a'] + mod) % mod;
            arr[s[i]-'a']=pre;
            pre=cur;
        }
        return cur;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends