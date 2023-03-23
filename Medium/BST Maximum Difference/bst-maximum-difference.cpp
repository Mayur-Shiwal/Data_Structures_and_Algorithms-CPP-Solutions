//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    Node* upperSum(Node* root, int target, int &rootToTarget){
        if(!root) return NULL;
        if(root->data == target) return root;
        rootToTarget += root->data;
        if(root->data > target) return upperSum(root->left, target, rootToTarget);
        if(root->data < target) return upperSum(root->right, target, rootToTarget);
        return NULL;
    }
    void lowerSum(Node* root, int &mini, int targetToLeaf){
        if(root == NULL) return;
        if(!root->left && !root->right){
            targetToLeaf += root->data;
            mini = min(mini, targetToLeaf);
        }
        targetToLeaf += root->data;
        lowerSum(root->left, mini, targetToLeaf);
        lowerSum(root->right, mini, targetToLeaf);
    }
public:
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int rootToTarget = 0;
        Node* targetRoot = upperSum(root, target, rootToTarget);
        if(!targetRoot) return -1;
        int mini = INT_MAX;
        lowerSum(targetRoot, mini, 0);
        mini -= target;
        return rootToTarget - mini;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends