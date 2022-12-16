//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)
    {
        // your code here
        if (n <= 1)
            return s;
        string res = "";
        int arr[27] = {0}, vov[27] = {0}, diff = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')  {
                vov[s[i] - 'a']++;
                diff++;
            }
            else {
                arr[s[i] - 'a']++;
                diff--;
            }
        }
        if (abs(diff) > 1)
            return "-1";
        // cout << diff << endl;
        int i = 0, j = 0;
        bool flag = true;
        while (arr[i] <= 0) i++;
        while (vov[j] <= 0) j++;
        if (i <= j || diff == -1) {
            res += i + 'a';
            res += j + 'a';
        }
        else {
            res += j + 'a';
            res += i + 'a';
            flag = false;
        }
        arr[i]--;
        vov[j]--;
        while (res.length() < n) {
            while (i < 26 && arr[i] <= 0) i++;
            while (j < 26 && vov[j] <= 0) j++;
            if (flag) {
                res += i + 'a';
                if (res.length() < n)
                    res += j + 'a';
            }
            else {
                res += j + 'a';
                if (res.length() < n)
                    res += i + 'a';
            }
            arr[i]--;
            vov[j]--;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends