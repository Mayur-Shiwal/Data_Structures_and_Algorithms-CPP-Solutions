//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans = "";
  int cnt = 1;
  int i = 1;
  while(i < src.length()){
      if(src[i-1] == src[i]) cnt++;
      else if(src[i] != src[i-1]){
          ans += src[i-1];
          ans += cnt + '0';
          cnt = 1;
      }
      i++;
  }
  ans += src[i-1];
  ans += cnt + '0';
  return ans;
}     
 
