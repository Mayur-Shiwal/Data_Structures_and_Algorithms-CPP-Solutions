//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    const long long int mod = 1e9 + 7;
    long long sequence(int n){
        // code here
        long long ans = 0;
        int cnt = 1;
        for(int i=1;i<=n;i++){
            int temp = i;
            // cnt = i;
            long long total = 1;
            while(temp--) total = (total * cnt++) % mod;
            ans = (ans + total) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends