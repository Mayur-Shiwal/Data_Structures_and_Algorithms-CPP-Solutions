//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    // 	long long int ans = 0;
    // 	for(int i=0;i<n;i++){
    // 	    for(int j=i+1;j<n;j++){
    // 	        ans += (arr[i] xor arr[j]);
    // 	    }
    // 	}
    // 	return ans;
        
        ll int ans = 0;
        for(int i=0;i<32;i++){
            ll int countZero = 0, countOne = 0;
            for(int j=0;j<n;j++){
                if(arr[j]%2 == 0) countZero++;
                else countOne++;
                arr[j] /= 2;
            }
            ans += countZero*countOne*(1<<i);
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
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends