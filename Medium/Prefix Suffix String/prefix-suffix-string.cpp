//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class TrieNode{
public:
    TrieNode *children[26];
};
TrieNode* getNode(){
    TrieNode* newNode = new TrieNode();
    for(int i=0;i<26;i++) newNode->children[i] = NULL;
    return newNode;
}
void insert(TrieNode* root, string key){
    TrieNode* currNode = root;
    for(int i=0;i<key.length();i++){
        int ind = key[i] - 'a';
        if(!currNode->children[ind]) currNode->children[ind] = getNode();
        currNode = currNode->children[ind];
    }
}
bool search(TrieNode* root, string key){
    TrieNode* currNode = root;
    for(int i=0;i<key.length();i++){
        int ind = key[i] - 'a';
        if(!currNode->children[ind]) return false;
        currNode = currNode->children[ind];
    }
    return true;
}

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        TrieNode* root = getNode();
        for(auto it: s1){
            insert(root, it);
            reverse(it.begin(), it.end());
            insert(root, it);
        }
        int ans = 0;
        for(auto it: s2){
            string rev = it;
            reverse(rev.begin(), rev.end());
            if(search(root, it) || search(root, rev)) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends