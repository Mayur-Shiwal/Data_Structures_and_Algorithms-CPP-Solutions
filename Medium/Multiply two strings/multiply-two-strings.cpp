//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       reverse(s1.begin(), s1.end());
       reverse(s2.begin(), s2.end());
       
       bool isNeg1 = false, isNeg2 = false;
       
       if(s1.back() == '-'){
           s1.pop_back();
           isNeg1 = 1;
       }
       if(s2.back() == '-'){
           s2.pop_back();
           isNeg2 = 1;
       }
       
       while(s1.back() == '0') s1.pop_back();
       while(s2.back() == '0') s2.pop_back();
       
       int n = s1.length(), m = s2.length();
       
       string ans(n + m, '0');
       for(int i=0;i<m;i++){
           int carry = 0, j;
           for(j=0;j<n;j++){
               int temp = (s2[i] - '0') * ( s1[j] - '0') + (ans[i+j] - '0') + carry;
               ans[i+j] = (char)('0' + temp%10);
               carry = temp/10;
           }
           while(carry){
               int temp = (ans[i+j] - '0') + carry;
               ans[i+j] = (char)('0' + temp%10);
               carry = temp / 10;
               ++j;
           }
       }
       while(ans.back() == '0') ans.pop_back();
       if(!ans.size()) return "0";
       if(isNeg1 ^ isNeg2) ans += '-';
       reverse(ans.begin(), ans.end());
       return ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends