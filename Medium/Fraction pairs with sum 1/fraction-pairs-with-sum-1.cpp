//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        int ans = 0;
        for(int i=0;i<n;i++){
            int gcd = __gcd(num[i], den[i]);
            num[i] = num[i] / gcd;
            den[i] = den[i] / gcd;
        }
        map<pair<int, int>, int> mp;
        for(int i=0;i<n;i++){
            if(mp.find({den[i] - num[i], den[i]}) != mp.end()){
                ans += mp[{den[i] - num[i], den[i]}];
                mp[{num[i], den[i]}]++;
            }
            else mp[{num[i], den[i]}]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends