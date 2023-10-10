//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution{
public:
    void dfs(Node* root, unordered_map<Node*, Node*>& parent){
        if(root == NULL) return;
        if(root->left){
            parent[root->left] = root;
            dfs(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            dfs(root->right, parent);
        }
    }
    
    void findNode(Node* root, Node* &targetNode, int t){
        if(root == NULL) return;
        if(root->data == t){
            targetNode = root;
            return;
        }
        if(root->left) findNode(root->left, targetNode, t);
        if(root->right) findNode(root->right, targetNode, t);
    }
    
    vector<int> KDistanceNodes(Node* root, int target, int k){
        Node* targetNode;
        findNode(root, targetNode, target);
        
        queue<Node*> q;
        q.push(targetNode);
        
        unordered_map<Node*, Node*> parent;
        parent[root] = NULL;
        dfs(root, parent);
        
        unordered_map<Node*, bool> vis;
        vis[targetNode] = true;
        
        int level = 0;
        while(!q.empty()){
            if(level++ == k) break;
            
            int size = q.size();
            
            for(int i=0; i<size; i++){
                Node* frontNode = q.front();
                q.pop();
                
                if(frontNode->left && !vis[frontNode->left]){
                    q.push(frontNode->left);
                    vis[frontNode->left] = 1;
                }
                
                if(frontNode->right && !vis[frontNode->right]){
                    q.push(frontNode->right);
                    vis[frontNode->right] = 1;
                }
                
                if(parent[frontNode] && !vis[parent[frontNode]]){
                    q.push(parent[frontNode]);
                    vis[parent[frontNode]] = 1;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends