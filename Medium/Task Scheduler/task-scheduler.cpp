//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int freq[26] = {0};
        int maxF = 0;
        for(auto it: tasks){
            freq[it - 'A']++;
            maxF = max(maxF, freq[it - 'A']);
        }
        int maxFcount = 0;
        for(int i=0;i<26;i++){
            if(freq[i] == maxF) maxFcount++;
        }
        int time = (maxF-1)*(K+1) + maxFcount;
        return max(time, N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends