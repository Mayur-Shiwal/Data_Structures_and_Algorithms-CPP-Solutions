//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int PartitionSubarray(int nums[], int tar, int n){
        int numberOfSubArray = 1;
        int tempSum = 0;
        for(int i=0;i<n;i++){
            if(tempSum + nums[i] <= tar) tempSum += nums[i];
            else{
                numberOfSubArray++;
                tempSum = nums[i];
            }
        }
        return numberOfSubArray;
    }
    int splitArray(int nums[] ,int n, int k) {
        // code here
        int l = 0;
        int r = 0;
        for(int i=0;i<n;i++) l = max(l, nums[i]), r += nums[i];
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            int count = PartitionSubarray(nums, mid, n);
            if(count <= k){
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends