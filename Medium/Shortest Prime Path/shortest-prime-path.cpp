//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isPrime(int n) {
        if(n == 1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int solve(int num1,int num2)
    {   
      //code here
      queue<pair<string, int>> q;
      string s1 = to_string(num1);
      string s2 = to_string(num2);
      q.push({s1, 0});
      vector<int> vis(1e5, 0);
      while(!q.empty()){
          string word = q.front().first;
          int steps = q.front().second;
          q.pop();
          vis[stoi(word)] = 1;
          if(word == s2) return steps;
          for(int i=0;i<word.size();i++){
              char ch = word[i];
              for(int j=0;j<10;j++){
                  if(i == 0 && j == 0) continue;
                  word[i] = char(j + '0');
                  if(isPrime(stoi(word)) && !vis[stoi(word)]){
                      vis[stoi(word)] = 1;
                      q.push({word, steps+1});
                  }
              }
              word[i] = ch;
          }
      }
      return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends