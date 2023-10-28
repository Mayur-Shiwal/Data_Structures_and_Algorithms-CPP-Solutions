//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool isValid(int i, int n){
        return i + __builtin_popcount(i) == n;
    }
public:
	int is_bleak(int n)
	{
	    // Code here.
	    //gives tle tc:NlogN;
	   // for(int i=1;i<n;i++){
	   //     if(i + __builtin_popcount(i) == n) return 0;
	   // }
	   // return 1;
	   
	   if(n > 32){
	       for(int i=n-32-1;i<n;i++){
	           if(isValid(i, n)) return 0;
	       }
	   }
	   else{
	       for(int i=1;i<n;i++){
	           if(isValid(i, n)) return 0;
	       }
	   }
	   return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends