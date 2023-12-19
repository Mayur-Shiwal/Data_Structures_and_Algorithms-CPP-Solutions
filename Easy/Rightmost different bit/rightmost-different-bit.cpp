//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        string s1 = bitset<32>(m).to_string();
        string s2 = bitset<32>(n).to_string();
        int i = s1.length()-1, j = s2.length()-1;
        int cnt = 1;
        while(i >= 0 && j >= 0){
            if(s1[i] != s2[j]) return cnt;
            i--;
            j--;
            cnt++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends