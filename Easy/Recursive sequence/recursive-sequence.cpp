//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      long long solve(int N)

    {

        if(N==1)

        {

            return 1;

        }

        if(N==2)

        {

            return 7;

        }

        int s=0;

        for(int i=0;i<N;i++)

        {

            s=s+i;

        }

        long long an=1;

        for(int i=s+N;i>s;i--)

        {

            an=an*(i);

        }

        return an+solve(N-1);

    }
    long long sequence(int N){
        return solve(N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends