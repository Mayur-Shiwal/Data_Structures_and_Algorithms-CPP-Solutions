//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool isPrime(int n){
            if(n == 1) return false;
            int range = sqrt(n);
            for(int i=2;i<=range;i++) if(n%i == 0) return false;
            return true;
        }
	public:
		int PrimePalindrome(int N){
		    // Code here
		    if(N >= 8 && N <= 11) return 11;
		    for(int i=1;i<=1e5;i++){
		        string s = to_string(i);
		        string t(s.rbegin(), s.rend());
		        int val = stoi(s + t.substr(1));
		        if(val >= N && isPrime(val)) return val;
		    }
		    return -1;
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.PrimePalindrome(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends