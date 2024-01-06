//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    int primeFactors(int n){
        if(n == 1) return 0;
        int cnt = 0;
        for(int i=2;i<=sqrt(n);++i){
            while(n%i == 0){
                n/=i;
                cnt++;
            }
        }
        if(n != 1) ++cnt;
        return cnt;
    }
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans = 0;
	    for(int i=a;i<=b;++i) ans += primeFactors(i);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends