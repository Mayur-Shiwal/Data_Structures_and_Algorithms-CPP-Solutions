//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans(n, 0);
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=0;j<n;j++){
        //         if(i == j) continue;
        //         if(arr[i] > arr[j]) sum += arr[j];
        //     }
        //     ans.push_back(sum);
        // }
        // return ans;
        // vector<int> nums = arr;
        // sort(nums.begin(), nums.end());
        // int i = 0;
        // while(i < n){
        //     int sum = 0;
        //     int j = 0;
        //     while(nums[j] < arr[i]){
        //         sum += nums[j++];
        //     }
        //     ans.push_back(sum);
        //     i++;
        // }
        // return ans;
        vector<long long> a(n+1, 0);
        vector<long long> val(n, 0);
        for(int i=0;i<n;i++) val[i] = arr[i];
        long sum = 0;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            sum += arr[i];
            a[i+1] = sum;
        }
        for(int i=0;i<n;i++){
            int num = lower_bound(arr.begin(), arr.end(), val[i]) - arr.begin();
            ans[i] = a[num];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends