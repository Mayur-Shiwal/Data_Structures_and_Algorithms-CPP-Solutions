//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(), range.end());
        int prev = range[0][0];
        int maxi = 0;
        vector<pair<int, int>> vp;
        for(int i=0;i<n;i++){
            if(range[i][0] > maxi && maxi > 0){
                vp.push_back({prev, maxi});
                prev = range[i][0];
            }
            maxi = max(maxi, range[i][1]);
        }
        vp.push_back({prev, maxi});
        vector<int> ans;
        for(int i=0;i<q;i++){
            int ch = 0;
            for(int j=0;j<vp.size();j++){
                if(vp[j].second - vp[j].first + 1 < queries[i]){
                    queries[i] = queries[i] - (vp[j].second - vp[j].first + 1);
                }
                else{
                    ans.push_back(vp[j].first + queries[i] - 1);
                    ch = 1;
                    break;
                }
            }
            if(ch == 0) ans.push_back(-1);
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends