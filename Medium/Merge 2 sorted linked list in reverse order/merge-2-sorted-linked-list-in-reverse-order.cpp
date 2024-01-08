//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    struct Node* reverseList(Node* head){
        if(!head) return NULL;
        Node* curr = head;
        Node* prev = NULL;
        while(curr){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        
        // Approach 1
        // if(!node1 && !node2) return NULL;
        // priority_queue<int> pq;
        // while(node1){
        //     pq.push(node1->data);
        //     node1 = node1->next;
        // }
        // while(node2){
        //     pq.push(node2->data);
        //     node2 = node2->next;
        // }
        // Node* head = newNode(pq.top());
        // pq.pop();
        // Node* refNode = head;
        // while(!pq.empty()){
        //     Node* temp = newNode(pq.top());
        //     pq.pop();
        //     head->next = temp;
        //     head = head->next;
        // }
        // return refNode;
        
        //Approach 2;
        Node* refNode = newNode(-1);
        Node* temp = refNode;
        while(node1 && node2){
            if(node1->data < node2->data){
                temp->next = node1;
                node1 = node1->next;
            }
            else{
                temp->next= node2;
                node2 = node2->next;
            }
            temp = temp->next;
        }
        while(node1){
            temp->next = node1;
            node1 = node1->next;
            temp = temp->next;
        }
        while(node2){
            temp->next = node2;
            node2 = node2->next;
            temp = temp->next;
        }
        return reverseList(refNode->next);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends