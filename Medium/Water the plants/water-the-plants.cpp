//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int, int>> cover(n);
        for(int i=0;i<n;++i){
            if(gallery[i] == -1) cover[i] = {1e7, 1e7};
            else cover[i] = {i-gallery[i], i+gallery[i]};
        }
        sort(cover.begin(), cover.end());
        int take = 0, ind = 0, ans = 0;
        while(take < n){
            int temp = take - 1;
            while(ind < n && cover[ind].first <= take) temp = max(temp, cover[ind++].second);
            if(temp + 1 > take){
                ++ans;
                take = temp+1;
            }
            else return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends