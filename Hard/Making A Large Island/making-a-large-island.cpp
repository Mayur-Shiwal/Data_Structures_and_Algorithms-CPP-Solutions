//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
private:
    bool checkValid(int i, int j, int n, int m){
        return (i<0 || j<0 || i>=n || j>=m) ? false : true;
    }
    void f(int i, int j, int id, int n, int m, int &cnt, vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] > 1 || grid[i][j] == 0) return;
        grid[i][j] = id;
        f(i-1, j, id, n, m, cnt, grid);
        f(i, j+1, id, n, m, cnt, grid);
        f(i+1, j, id, n, m, cnt, grid);
        f(i, j-1, id, n, m, cnt, grid);
        cnt++;
    } 
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> mp;
        int mp_id = 2;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    f(i, j, mp_id, n, m, cnt, grid);
                    mp[mp_id++] = cnt;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    int sum = 0;
                    set<int> st;
                    if(checkValid(i-1, j, m, n) && grid[i-1][j] > 1 && st.find(grid[i-1][j]) == st.end()){
                        st.insert(grid[i-1][j]);
                        auto it = mp.find(grid[i-1][j]);
                        sum += it->second;
                    }
                    if(checkValid(i, j+1, m, n) && grid[i][j+1] > 1 && st.find(grid[i][j+1]) == st.end()){
                        st.insert(grid[i][j+1]);
                        auto it = mp.find(grid[i][j+1]);
                        sum += it->second;
                    }
                    if(checkValid(i+1, j, m, n) && grid[i+1][j] > 1 && st.find(grid[i+1][j]) == st.end()){
                        st.insert(grid[i+1][j]);
                        auto it = mp.find(grid[i+1][j]);
                        sum += it->second;
                    }
                    if(checkValid(i, j-1, m, n) && grid[i][j-1] > 1 && st.find(grid[i][j-1]) == st.end()){
                        st.insert(grid[i][j-1]);
                        auto it = mp.find(grid[i][j-1]);
                        sum += it->second;
                    }
                    sum++;
                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi == INT_MIN ? n*m : maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends