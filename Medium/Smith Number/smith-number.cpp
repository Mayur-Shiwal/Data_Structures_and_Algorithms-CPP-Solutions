//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    bool isPrime(int n){
        if(n == 1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int sumOfNum(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n/=10;
        }
        return ans;
    }
    int sumOfPrime(int n){
        int temp = 1;
        int sum = 0;
        while(n > 1){
            ++temp;
            if(!isPrime(temp)) continue;
            while(n % temp == 0){
                sum += sumOfNum(temp);
                n /= temp;
            }
        }
        return sum;
    }
public:
    int smithNum(int n) {
        // code here
        if(isPrime(n)) return 0;
        return sumOfPrime(n) == sumOfNum(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends