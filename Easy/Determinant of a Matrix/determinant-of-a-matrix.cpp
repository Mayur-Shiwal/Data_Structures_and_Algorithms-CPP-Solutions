//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        if(n==1) return matrix[0][0];
        vector<vector<int>>submat(n-1,vector<int>(n-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int x=0;
                for(int k=0;k<n;k++){
                    if(k==i) continue;
                    submat[j-1][x++]=matrix[j][k];
                }
            }
            ans+=(matrix[0][i]*determinantOfMatrix(submat,n-1)*((i&1)==1?-1:1));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends