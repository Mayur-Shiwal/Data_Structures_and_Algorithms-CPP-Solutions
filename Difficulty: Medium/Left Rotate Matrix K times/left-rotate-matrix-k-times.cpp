//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int row = mat.size(), column = mat[0].size();
        vector<vector<int>> result(row, vector<int>(column, 0));
        k = k%column;
        if(k==0) return mat;
        for(int i=0;i<row;i++)
        {
             int z=0;
             for(int j=k ; j < column  ; j++)
              {
                  result[i][z++]=mat[i][j];
              }
              
              for(int j=0 ; j < k  ; j++)
              {
                  result[i][z++]=mat[i][j];
              }
         }
        
        return result;
    }
};


/*

1, 2, 3
4, 5, 6
7, 8, 9

*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends