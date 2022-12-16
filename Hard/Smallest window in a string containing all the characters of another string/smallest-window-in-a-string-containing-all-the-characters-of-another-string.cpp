//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;
        int len_s = s.size();
        int len_t = t.size();
        if(len_s < len_t) return "-1";
        for(int i=0;i<len_t;i++) tmp[t[i]]++;
        int count = 0;
        int st = 0;
        int min_len = INT_MAX;
        int st_ind = 0;
        int end_ind = 0;
        for(int j=0;j<len_s;j++){
            smp[s[j]]++;
            if(smp[s[j]] <= tmp[s[j]]) count++;
            if(count == len_t){
                if(smp[s[st]] > tmp[s[st]]){
                    while(smp[s[st]] > tmp[s[st]]){
                        smp[s[st]]--;
                        st++;
                    }
                }
                if(min_len > j - st + 1){
                    min_len = j - st + 1;
                    st_ind = st;
                    end_ind = j;
                }
            }
        }
        string ans = "";
        for(int i=st_ind;i<=end_ind;i++) ans += s[i];
        return min_len == INT_MAX ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends