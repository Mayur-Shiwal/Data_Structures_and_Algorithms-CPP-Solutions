//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    //1st approach
	   // int i = 0, j = 0;
	   // while(i < n && arr[i] != x) i++;
	   // if(i == n) return 0;
	   // j = i;
	   // while(j < n && arr[j] == x) j++;
	   // return j - i;
	   
	   //2nd approach
	   //int ans = 0;
	   //for(int i=0;i<n;i++){
	   //    if(arr[i] == x) ans++;
	   //}
	   //return ans;
	   
	   //3rd approach
	   unordered_map<int, int> mp;
	   for(int i=0;i<n;i++) mp[arr[i]]++;
	   return (mp.find(x) != mp.end()) ? mp[x] : 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
