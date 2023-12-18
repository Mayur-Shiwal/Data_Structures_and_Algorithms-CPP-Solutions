//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int n, int arr[]) {
        // code here
        int totalSubarrays = (n*(n+1))/2;
        int x = 0;
        for(int i=0; i<n; i++){
            int prev = (i-0);
            int succ = (n-i-1);
            int subOcc = totalSubarrays-((prev*(prev+1))/2 + (succ*(succ+1)/2));
            if(subOcc%2 == 0)continue;
            else x ^= arr[i];
        }
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends