//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int horizontal = 0;
        int vertical = 0;
        int maxHorizontal = 0;
        int minHorizontal = 0;
        int maxVertical = 0;
        int minVertical = 0;
        for(auto it: s){
            if(it == 'R') horizontal++;
            if(it == 'L') horizontal--;
            if(it == 'U') vertical--;
            if(it == 'D') vertical++;
            maxHorizontal = max(maxHorizontal, horizontal);
            minHorizontal = min(minHorizontal, horizontal);
            maxVertical = max(maxVertical, vertical);
            minVertical = min(minVertical, vertical);
        }
        return ((maxHorizontal + abs(minHorizontal) + 1) > m || (maxVertical + abs(minVertical) + 1) > n) ? 0 : 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends