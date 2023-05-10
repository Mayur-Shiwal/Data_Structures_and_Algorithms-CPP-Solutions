//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int> v1(N, 0);
        vector<int> v2(N, 0);
        int m = INT_MIN;
        int ans = 0;
        for(int i=0;i<N;i++){
            m = max(m, A[i]);
            v1[i] = m;
        }
        m = INT_MAX;
        for(int i=N-1;i>=0;i--){
            m = min(m, A[i]);
            v2[i] = m;
        }
        for(int i=0;i<N-1;i++){
            if(v1[i] + v2[i+1] >= K) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends