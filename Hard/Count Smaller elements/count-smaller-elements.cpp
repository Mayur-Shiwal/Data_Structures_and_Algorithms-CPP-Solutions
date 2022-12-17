//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
        vector<pair<int, int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        while(i <= mid && j <= right){
            if(v[i].first <= v[j].first) temp[k++] = v[j++];
            else{
                count[v[i].second] += right - j + 1;
                temp[k++] = v[i++];
            }
        }
        while(i <= mid) temp[k++] = v[i++];
        while(j <= right) temp[k++] = v[j++];
        for(int i=left;i<=right;i++) v[i] = temp[i - left];

    }
    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right){
        if(left < right){
            int mid = left + (right - left) / 2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
        }
    }
	vector<int> constructLowerArray(int *nums, int n) {
	    // code here
	    vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        vector<int> countNumbers(n, 0);
        mergeSort(countNumbers, v, 0, n-1);
        return countNumbers;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends