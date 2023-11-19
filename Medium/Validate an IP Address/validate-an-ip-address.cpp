//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int numberOfDots = 0;
            for(int i=0;i<s.length();i++){
                if(s[i] == '.') numberOfDots++;
            }
            if(numberOfDots == 3){
                string str = "";
                stringstream ss(s);
                while(getline(ss, str, '.')){
                    for(int i=0;i<str.length();i++){
                        if(!isdigit(str[i])) return 0;
                    }
                    if(str.length() == 0 || str.length() > 3) return 0;
                    int temp = stoi(str);
                    if(temp < 0 || temp > 255) return 0;
                    if(str.length() > 1 && str[0] == '0') return 0;
                }
                return (str.length() == 0) ? 0 : 1;
            }
            else return 0;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends