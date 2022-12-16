//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int row = mat.size();
        int col = mat[0].size();
        // if(row == 0) return 0;
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        int maxSquareArea = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j]==0) dp[i][j]=0;
                else{
                    dp[i][j]=1+min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]));
                    if(maxSquareArea<dp[i][j]){
                        maxSquareArea=dp[i][j];
                    }
                }
            }
        }
        return maxSquareArea;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends