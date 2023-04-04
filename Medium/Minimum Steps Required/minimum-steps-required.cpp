//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int a = 0;
    int b = 0;
    if(str[0] == 'a') a++;
    else b++;
    for(int i=1;i<str.length();i++){
        if(str[i-1] != str[i]){
            if(str[i] == 'a') a++;
            else b++;
        }
    }
    return min(a, b) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends