//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int ZigZagMaxLength(vector<int>&nums){
		    // Code here
		    if(nums.size() < 2) return nums.size();
            int prev = nums[1] - nums[0];
            int count = prev != 0 ? 2 : 1;
            for(int i=2;i<nums.size();i++){
                int diff = nums[i] - nums[i-1];
                if((diff > 0 && prev <= 0) || (diff < 0 && prev >= 0)){
                    count++;
                    prev = diff;
                }
            }
            return count;
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
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends