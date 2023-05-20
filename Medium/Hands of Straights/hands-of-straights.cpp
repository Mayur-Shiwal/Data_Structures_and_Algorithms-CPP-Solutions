//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N % groupSize) return false;
        map<int, int> mp;
        for(auto it: hand) mp[it]++;
        int num = -1;
        while(true){
            num = mp.begin()->first;
            int cnt = 0;
            while(cnt < groupSize){
                if(mp[num] == 0) return false;
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);
                num++;
                cnt++;
            }
            if(mp.size() == 0) break;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends