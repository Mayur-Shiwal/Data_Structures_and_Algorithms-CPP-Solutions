//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> ans;
            map<int, int> mp;
            mp[A[0]]++;
            mp[B[0]]++;
            mp[C[0]]++;
            for(int i=1;i<n1;i++){
                if(A[i] != A[i-1]) mp[A[i]]++;
            }
            for(int i=1;i<n2;i++){
                if(B[i] != B[i-1]) mp[B[i]]++;
            }
            for(int i=1;i<n3;i++){
                if(C[i] != C[i-1]) mp[C[i]]++; 
            }
            for(auto it: mp){
                if(it.second == 3) ans.push_back(it.first);
            }
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends