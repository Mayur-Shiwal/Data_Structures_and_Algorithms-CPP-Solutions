//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f(int ind, string &str, vector<string> &ans){
        if(ind == str.length()){
            ans.push_back(str);
            return;
        }
        for(int i=ind;i<str.length();i++){
            swap(str[i], str[ind]);
            f(ind+1, str, ans);
            swap(str[i], str[ind]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        f(0, S, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends