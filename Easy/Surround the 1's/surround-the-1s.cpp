//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    bool isValid(int i, int j, vector<vector<int>> &matrix){
        int cnt = 0;
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow = i + delrow;
                int ncol = j + delcol;
                if(nrow >= 0 && nrow < matrix.size() && ncol >= 0 && ncol < matrix[0].size() && matrix[nrow][ncol] == 0) cnt++;
            }
        }
        return cnt && cnt%2 == 0;
    }
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int ans = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j] == 1){
                    if(isValid(i, j, matrix)) ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends