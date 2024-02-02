//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = str.size();
        int ans = 0;
        int i;
        if(str[0]=='-') i=1;
        else i=0;
        while(i<n){
            if((str[i] - '0') > 9 || str[i] - '0' < 0) return -1;
            ans = ans * 10 + (str[i] - '0');
            i++;
        }
        if(str[0] == '-') return -ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends