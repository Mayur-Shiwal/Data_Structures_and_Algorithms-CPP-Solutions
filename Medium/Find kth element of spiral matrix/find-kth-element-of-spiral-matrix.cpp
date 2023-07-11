//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int cnt = 0;
 		int sr = 0;
 		int er = n-1;
 		int sc = 0;
 		int ec = m-1;
 		while(1){
 		    if(sr > er) break;
 		    if(sc > ec) break;
 		    for(int i=sc;i<=ec;i++){
 		        if(cnt == k-1) return a[sr][i];
 		        cnt++;
 		    }
 		    sr++;
 		    for(int i=sr;i<=er;i++){
 		        if(cnt == k-1) return a[i][ec];
 		        cnt++;
 		    }
 		    ec--;
 		    for(int i=ec;i>=sc;i--){
 		        if(cnt == k-1) return a[er][i];
 		        cnt++;
 		    }
 		    er--;
 		    for(int i=er;i>=sr;i--){
 		        if(cnt == k-1) return a[i][sc];
 		        cnt++;
 		    }
 		    sc++;
 		}
 		return cnt;
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
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends