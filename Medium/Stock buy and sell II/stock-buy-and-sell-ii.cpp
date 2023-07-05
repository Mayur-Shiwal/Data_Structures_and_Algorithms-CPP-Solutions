//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    int f(int ind, int n, int buy, vector<vector<int>>&dp, vector<int>&prices){
      if(ind==n){
          return 0;
      }
      if(dp[ind][buy]!=-1) return dp[ind][buy];
      if(buy==1){
          int bought=-prices[ind]+f(ind+1,n,0,dp,prices);
          int not_bought=f(ind+1,n,1,dp,prices);
          return dp[ind][buy]= max(bought,not_bought);
      }
      else{
          int sold=prices[ind]+f(ind+1,n,1,dp,prices);
          int not_sold=f(ind+1,n,0,dp,prices);
          return dp[ind][buy]= max(sold,not_sold);
      }
    }
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        //approach 1
        // int ans = 0;
        // for(int i=0;i<n-1;i++){
        //     if(prices[i] < prices[i+1]) ans += (prices[i+1] - prices[i]);
        // }
        // return ans;
        
        //approach2
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, n, 1, dp, prices);
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends