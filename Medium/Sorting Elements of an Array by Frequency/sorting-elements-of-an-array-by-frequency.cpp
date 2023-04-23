#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.first != b.first) ? a.first > b.first : a.second < b.second;
}
vector<int> solve(int arr[], int n){
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    vector<pair<int, int>> v;
    for(auto it: mp) v.push_back({it.second, it.first});
    vector<int> ans;
    sort(v.begin(), v.end(), cmp);
    for(auto it: v){
        int j = it.first;
        while(j--) ans.push_back(it.second);
    }
    return ans;
}
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> v = solve(arr, n);
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}