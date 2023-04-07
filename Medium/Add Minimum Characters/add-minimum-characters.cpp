//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    // bool isPalindrome(string s){
    //     int i = 0;
    //     int j = s.length()-1;
    //     while(i <= j){
    //         if(s[i++] != s[j--]) return false;
    //     }
    //     return true;
    // }
    int addMinChar(string str){    
        //code here
        // int count = 1;
        // if(isPalindrome(str)) return 0;
        // string s = str;
        // reverse(s.begin(), s.end());
        // string temp = "";
        // for(int i=0;i<s.length();i++){
        //     temp += s[i];
        //     string t = "";
        //     t = temp + str;
        //     if(isPalindrome(t)) break;
        //     else count++;
        // }
        // return count;
        int i = 0;
        int j = str.length() -1;
        int cnt = j;
        while(i < j){
            if(str[i] == str[j]) i++;
            else{
                i = 0;
                j = cnt;
                cnt--;
            }
            j--;
        }
        return str.length() - cnt - 1;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends