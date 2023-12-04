//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string findSum(string &s1,string &s2){
        string ans="";
        int i=s1.size()-1,j=s2.size()-1,carry=0,sum,rem;
        while(i>=0 || j>=0 || carry){
            sum=(i>=0?s1[i--]-'0':0)+(j>=0?s2[j--]-'0':0)+carry;
            rem=sum%10;
            carry=sum/10;
            ans.push_back(rem+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool solve(string &s,int pos, int ln1,int ln2){
        string s1=s.substr(pos,ln1);
        string s2=s.substr(pos+ln1,ln2);
        string sum=findSum(s1,s2);
        if(sum.size()>s.size()-(pos+ln1+ln2))return false;
        
        if(sum==s.substr(pos+ln1+ln2,sum.size())){
            if(sum.size()==s.size()-(pos+ln1+ln2))return true;
            return solve(s,pos+ln1,ln2,sum.size());
        }
        return false;
    }
    int isSumString(string S){
        for(int i=1;i<S.size();i++){
            for(int j=1;j<=S.size()-i;j++){
                if(solve(S,0,i,j))return 1;
            }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends