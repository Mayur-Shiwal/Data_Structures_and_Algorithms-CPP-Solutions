//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        for(int i=0;i<k;i++){
            int kval = q.front();
            q.pop();
            s.push(kval);
        }
        //step 2: fecth from stack and push into queue
        while(!s.empty()){
            int kval = s.top();
            s.pop();
            q.push(kval);
        }
        //step 3: fetch 1st n-k elements from q and push_back
        int x = q.size()-k;
        while(x--){
            int kval = q.front();
            q.pop();
            q.push(kval);
        }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends