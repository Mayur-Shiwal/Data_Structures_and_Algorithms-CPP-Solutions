//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        int ans = INT_MAX;
        while(!q.empty()){
            auto frontEle = q.front();
            q.pop();
            int steps = frontEle.second;
            int x = frontEle.first.first;
            int y = frontEle.first.second;
            if(x == X && y == Y){
                ans = min(ans, steps);
            }
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(abs(delrow) == abs(delcol)) continue;
                    int nrow = x + delrow;
                    int ncol = y + delcol;
                    if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && !vis[nrow][ncol] && A[nrow][ncol] == 1){
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, steps+1});
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends