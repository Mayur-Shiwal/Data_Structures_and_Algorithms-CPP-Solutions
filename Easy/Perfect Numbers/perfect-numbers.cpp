//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        long long cnt = 0;
        for(long long i = 1;i <= sqrt(N);i++){
            if(N%i == 0){
                if(N/i == i) cnt += i;
                else{
                    cnt += i;
                    cnt += N/i;
                }
            }
        }
        cnt -= N;
        return cnt == N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends