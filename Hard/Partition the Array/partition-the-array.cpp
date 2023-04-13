//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    typedef pair<long long, long long> ppl;
    ppl minmax(long long pre[], int l, int r){
        int lo = l;
        int hi = r-1;
        long long minSum = 0;
        long long maxSum = pre[r] - pre[l-1];
        while(lo <= hi){
            int mid = lo + (hi - lo) /2;
            long long lsum = pre[mid] - pre[l-1];
            long long rsum = pre[r] - pre[mid];
            if(abs(rsum - lsum) < maxSum - minSum){
                minSum = min(lsum, rsum);
                maxSum = max(lsum, rsum);
            }
            if(lsum < rsum) lo = mid + 1;
            else hi = mid - 1;
        }
        return {minSum, maxSum};
    }
    long long minDifference(int N, vector<int> &A) {
        // code here
        long long preSum[N+1];
        preSum[0] = 0;
        for(int i=0;i<=N;i++) preSum[i] = preSum[i-1] + A[i-1];
        long long ans = preSum[N];
        for(int i=1;i<N-2;i++){
            ppl mml = minmax(preSum, 1, i+1);
            ppl mmr = minmax(preSum, i+2, N);
            ans = min(ans, max(mml.second, mmr.second) - min(mml.first, mmr.first));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends