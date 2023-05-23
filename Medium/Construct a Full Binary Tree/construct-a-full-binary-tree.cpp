//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* f(int &ind, int st, int end, int pre[], int preMirror[], int n){
        if(st == end){
            Node* temp = new Node(pre[ind]);
            ind++;
            return temp;
        }
        Node* root = new Node(pre[ind]);
        ind++;
        for(int i=st;i<=end;i++){
            if(pre[ind] == preMirror[i]){
                root->left = f(ind, i, end, pre, preMirror, n);
                root->right = f(ind, st+1, i-1, pre, preMirror, n);
                break;
            }
        }
        return root;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int ind = 0;
        return f(ind, 0, size-1, pre, preMirror, size);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends