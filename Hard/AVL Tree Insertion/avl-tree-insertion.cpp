//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
public:
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    Node* rotateRight(Node* currentNode) {
        Node* newRoot = currentNode->left;
        Node* newRootRightSubtree = newRoot->right;

        newRoot->right = currentNode;
        currentNode->left = newRootRightSubtree;

        currentNode->height = max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* rotateLeft(Node* currentNode) {
        Node* newRoot = currentNode->right;
        Node* newRootLeftSubtree = newRoot->left;

        newRoot->left = currentNode;
        currentNode->right = newRootLeftSubtree;

        currentNode->height = max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    int getBalance(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* insertToAVL(Node* node, int data) {
        // Base case: If the node is null, create a new node with the given data.
        if (node == nullptr) {
            return new Node(data);
        }

        // Recursive insertions
        if (node->data > data) {
            node->left = insertToAVL(node->left, data);
        } else if (node->data < data) {
            node->right = insertToAVL(node->right, data);
        } else {
            // Duplicate data is not allowed in AVL trees.
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        
        int balance = getBalance(node);

        
        if (balance > 1 && node->left->data > data) {
            return rotateRight(node);
        }
        if (balance < -1 && node->right->data < data) {
            return rotateLeft(node);
        }
        if (balance > 1 && node->left->data < data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && node->right->data > data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
};


//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends