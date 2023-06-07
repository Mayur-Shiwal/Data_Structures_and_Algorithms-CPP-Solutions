//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> PrimeFactors(n+1);
        PrimeFactors[1] = 1;
        for(int i=2;i<=n;i++) PrimeFactors[i] = i;
        for(int i=2;i<=n;i++){
            if(PrimeFactors[i] == i){
                for(int j=i*i;j<=n;j+=i){
                    if(PrimeFactors[j] == j) PrimeFactors[j] = i;
                }
            }
        }
        return PrimeFactors;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends