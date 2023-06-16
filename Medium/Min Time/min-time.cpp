//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    unordered_map<int, int> mp1, mp2;
    long long f(int pos, int ind, vector<int> &v, vector<vector<long long>> &dp, int indication){
        if(ind == v.size()) return 0;
        if(dp[ind][indication] != -1) return dp[ind][indication];
        int left = mp1[v[ind]];
        int right = mp2[v[ind]];
        long long firstPos = abs(pos - left) + abs(left - right) + f(right, ind+1, v, dp, 1);
        if(ind == v.size()-1) firstPos += abs(right - 0);
        long long secondPos = abs(pos - right) + abs(left - right) + f(left, ind+1, v, dp, 0);
        if(ind == v.size()-1) secondPos += abs(left - 0);
        return dp[ind][indication] = min(firstPos, secondPos);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        int maxi = *max_element(types.begin(), types.end());
        vector<int> ele(maxi+1, 0);
        for(int i=0;i<n;i++){
            ele[types[i]] = 1;
            if(mp1.find(types[i]) == mp1.end()){
                mp1[types[i]] = locations[i];
                mp2[types[i]] = locations[i];
            }
            else{
                mp1[types[i]] = min(mp1[types[i]], locations[i]);
                mp2[types[i]] = max(mp2[types[i]], locations[i]);
            }
        } 
        vector<int> temp;
        for(int i=0;i<=maxi;i++){
            if(ele[i] == 1) temp.push_back(i);
        }
        vector<vector<long long>> dp(temp.size(), vector<long long>(2, -1));
        return f(0, 0, temp, dp, 0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
