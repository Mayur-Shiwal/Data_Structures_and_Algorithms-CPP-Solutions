//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
private:
    bool dfs(int n, int k, int total_posibilities, string &path, set<string> &vis){
        if(vis.size() == total_posibilities) return true;
        for(int i=0;i<k;i++){
            string currNode = path.substr(path.size()-n+1);
            currNode.push_back('0' + i);
            if(vis.find(currNode) == vis.end()){
                vis.insert(currNode);
                path.push_back('0' + i);
                if(dfs(n, k, total_posibilities, path, vis)) return true;
                path.pop_back();
                vis.erase(currNode);
            }
        }
        return false;
    }
public:
    string findString(int n, int k) {
        // code here
        string path = string(n-1, '0');
        set<string> vis;
        int total_posibilities = pow(k, n);
        dfs(n, k, total_posibilities, path, vis);
        return path;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends