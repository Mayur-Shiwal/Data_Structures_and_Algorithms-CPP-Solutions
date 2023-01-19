//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        if((a <= c && b <= d) || (a <= d && b <= c)) return 0;
        if(a > c && a > d) return 1 + carpetBox(a / 2, b, c, d);
        if(b > c && b > d) return 1 + carpetBox(a, b / 2, c, d);
        return min(1 + carpetBox(a/2, b, c, d), 1 + carpetBox(a, b/2, c, d));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends