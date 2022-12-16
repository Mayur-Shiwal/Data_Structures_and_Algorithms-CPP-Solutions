//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    bool isPrime(int n){
        if(n<2 || n%2==0 || n%3==0)
            return false;
        for(int i=5; i*i <= n; i+=6){
            if(n%i==0 || n%(i+2)==0)
                return false;
        }
        return true;
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
        for(int i=0; i<q; i++){
            int x = sqrt(query[i]);
            int count = 0;
            if(2 <= x)
            count++;
            if(3 <= x)
            count++;
            for(int j=5; j<=x; j+=6){
                if(isPrime(j))
                count++;
                if(isPrime(j+2) && (j+2)<=x)
                count++;
            }
            ans.emplace_back(count);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends