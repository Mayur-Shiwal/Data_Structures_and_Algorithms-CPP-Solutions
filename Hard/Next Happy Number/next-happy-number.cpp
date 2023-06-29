//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
private:
    bool f(int n){
        if(n == 1 || n == 7) return true;
        if(n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9) return false;
        int squareSum = 0;
        while(n){
            int remainder = n % 10;
            squareSum += (remainder * remainder);
            n /= 10;
        }
        return f(squareSum);
    }
public:
    int nextHappy(int N){
        // code here
        while(true){
            N++;
            if(f(N)) return N;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends