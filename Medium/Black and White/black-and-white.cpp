//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    int dx[] = {2, 2, 1, -1, -1, 1, -2, -2};
    int dy[] = {-1, 1, -2, -2, 2, 2, 1, -1};
    long mod = 1e9 + 7;
    long total = ((M * N)%mod * (M * N - 1)%mod) % mod;
    int attack = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<8;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x>=0 && x<N && y>=0 && y<M) attack++;
            }
        }
    }
    return (total - attack)%mod;
    
}