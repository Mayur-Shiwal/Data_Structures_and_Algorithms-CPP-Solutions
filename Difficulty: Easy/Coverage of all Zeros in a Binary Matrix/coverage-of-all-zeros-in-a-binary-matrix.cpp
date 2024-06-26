//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    if(i == 0 && j == 0){
                        if(i+1 < matrix.size()){
                            if(matrix[i+1][j] == 1) ans++;
                        }
                        if(j+1 < matrix[i].size()){
                            if(matrix[i][j+1] == 1) ans++;
                        }
                    }
                    else if(i == 0){
                        if(i+1 < matrix.size()){
                            if(matrix[i+1][j] == 1) ans++;
                        }
                        if(j+1 < matrix[i].size()){
                            if(matrix[i][j+1] == 1) ans++;
                        }
                        if(matrix[i][j-1] == 1) ans++;
                    }
                    else if(j == 0){
                        if(i+1 < matrix.size()){
                            if(matrix[i+1][j] == 1) ans++;
                        } 
                        if(j+1 < matrix[i].size()) {
                            if(matrix[i][j+1] == 1) ans++;
                        }
                        if(matrix[i-1][j] == 1) ans++;
                    }
                    else{
                        if(i+1 < matrix.size()){
                            if(matrix[i+1][j] == 1) ans++;
                        }
                        if(j+1 < matrix[i].size()){
                            if( matrix[i][j+1] == 1) ans++;
                        }
                        if(matrix[i-1][j] == 1) ans++;
                        if(matrix[i][j-1] == 1) ans++;
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends