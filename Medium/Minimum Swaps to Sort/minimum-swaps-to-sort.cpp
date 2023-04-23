//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> arr = nums;
	    sort(arr.begin(), arr.end());
	    map<int, int> mp;
	    int ans = 0;
	    for(int i=0;i<nums.size();i++) mp[nums[i]] = i;
	    for(int i=0;i<nums.size();i++){
	        if(arr[i] != nums[i]){
	            int t = mp[arr[i]];
	            swap(nums[i], nums[t]);
	            swap(mp[nums[i]], mp[nums[t]]);
	            ans++;
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
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends