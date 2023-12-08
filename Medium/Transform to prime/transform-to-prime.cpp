//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    bool isPrime(int num){
        if(num == 1 || num == 0) return false;
        for(int i=2;i<=num/2;i++){
            if(num%i == 0) return false;
        }
        return true;
    }
    public:
    int minNumber(int arr[],int N){
        int totalSum = 0;
        for(int i=0;i<N;i++) totalSum += arr[i];
        int temp = totalSum;
        while(isPrime(temp) == 0) temp++;
        return temp - totalSum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends