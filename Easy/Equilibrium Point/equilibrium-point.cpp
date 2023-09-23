//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        vector<int> v1;
        vector<int> v2;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i];
            v1.push_back(sum);
        }
        sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += a[i];
            v2.push_back(sum);
        }
        reverse(v2.begin(), v2.end());
        for(int i=0;i<n;i++){
            if(v1[i] == v2[i]) return i+1;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends