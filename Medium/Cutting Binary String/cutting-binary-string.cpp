//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool powerOf5(string s, int start, int end){
        long long num = 0;
        long long j = 1;
        for(int i=end;i>=start;i--){
            if(s[i] == '1') num += j;
            j *= 2;
        }
        while(num > 1){
            if(num%5 != 0) return false;
            num /= 5;
        }
        return true;
    }
    int f(string s, int start, int end){
        if(end < start) return 0;
        if(s[start] == '0') return -1;
        if(powerOf5(s, start, end)) return 1;
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            if(powerOf5(s, start, i)){
                int next = f(s, i+1, end);
                if(next != -1) ans = min(ans, 1 + next);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
    int cuts(string s){
        //code
        int n = s.length();
        return f(s, 0, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends