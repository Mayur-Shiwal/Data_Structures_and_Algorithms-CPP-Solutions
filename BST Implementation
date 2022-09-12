#include <iostream>
#include <queue>

using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }

};

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<frontNode->data<<" ";
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }

}

Node* insertIntoBST(Node* root, int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data>root->data){
        //right part me jana hai
        root->right = insertIntoBST(root->right,data);
    }
    else{
        //left part me jana hai
        root->left = insertIntoBST(root->left,data);
    }
    return root;

}

Node* minVal(Node* root){

    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root,int val){

    //base case
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->right==NULL && root->left!=NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->right!=NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }


    }
    else if(root->data>val){
            //left part me jana hai
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        //right part me jana hai
        root->right = deleteFromBST(root->right,val);
        return root;
    }


}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelOrderTraversal(root);

    //we can print inorder preorder postorder from previous tree implementation

    cout<<"Minimum Val is: "<<minVal(root)->data<<endl;
    cout<<"Maximum val is: "<<maxVal(root)->data<<endl;

    //deletion
    root = deleteFromBST(root,30);

    cout<<"Printing the BST: "<<endl;
    levelOrderTraversal(root);

    //we can print inorder preorder postorder from previous tree implementation

    cout<<"Minimum Val is: "<<minVal(root)->data<<endl;
    cout<<"Maximum val is: "<<maxVal(root)->data<<endl;

    return 0;
}
