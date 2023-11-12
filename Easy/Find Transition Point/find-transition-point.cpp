//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        if(n == 1) return (arr[0] == 1) ? 0 : -1;
        int i = 0, j = n-1;
        while(i <= j){
            int mid = i + (j - i)/2;
            if(arr[mid] == 1) j = mid-1;
            else i = mid+1;
        }
        return (i >= n-1) ? -1 :j+1;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends