//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        // int ans = 0;
        // for(int i=1;i<=N;i++){
        //     string s = bitset<32> (i).to_string();
        //     for(int j=0;j<s.length();j++){
        //         if(s[j] == '1') ans++;
        //     }
        // }
        // return ans;
        int ans = 0;
        for(int i=1;i<=N;i++) ans += __builtin_popcount(i);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends