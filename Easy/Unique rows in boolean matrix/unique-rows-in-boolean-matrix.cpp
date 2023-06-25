//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<row;i++){
            vector<int> temp;
            for(int j=0;j<col;j++){
                temp.push_back(M[i][j]);
            }
            st.insert(temp);
        }
        for(int i=0;i<row;i++){
            vector<int> temp;
            for(int j=0;j<col;j++){
                temp.push_back(M[i][j]);
            }
            if(st.find(temp) != st.end()){
                ans.push_back(temp);
                st.erase(temp);
            }
        }
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
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends