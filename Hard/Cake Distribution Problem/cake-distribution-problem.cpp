//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    bool sweetnessProvide(int mid, vector<int> &nums, int k){
        int totalPeices = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum >= mid){
                totalPeices++;
                sum = 0;
            }
        }
        return (totalPeices >= k+1) ? true : false;
    }  
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        // Write your code here.
        int l = *min_element(sweetness.begin(), sweetness.end());
        int h = accumulate(sweetness.begin(), sweetness.end(), 0);
        while(l <= h){
            int mid = l + (h - l)/2;
            if(sweetnessProvide(mid, sweetness, K)) l = mid + 1;
            else h = mid - 1;    
        }
        return l-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends