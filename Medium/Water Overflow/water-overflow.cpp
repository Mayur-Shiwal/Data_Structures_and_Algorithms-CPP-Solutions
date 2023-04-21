//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        double mat[501][501] = {0.0};
        mat[0][0] = K;
        for(int i=0;i<501;i++){
            for(int j=0;j<=i;j++){
                if(mat[i][j] >= 1){
                    mat[i+1][j] += (mat[i][j]-1)/2.0;
                    mat[i+1][j+1] += (mat[i][j]-1)/2.0;
                    mat[i][j] = 1;
                }
            }
        }
        return mat[R-1][C-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
// } Driver Code Ends