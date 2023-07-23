//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroes = NULL;
        Node* ones = NULL;
        Node* twos = NULL;
        Node* zeroesTail = NULL;
        Node* onesTail = NULL;
        Node* twosTail = NULL;
        Node* currNode = head;
        
        while(currNode){
            if(currNode->data == 0){
                if(zeroes == NULL){
                    zeroes = currNode;
                    zeroesTail = currNode;
                }
                else{
                    zeroesTail->next = currNode;
                    zeroesTail = zeroesTail->next;
                }
            }
            else if(currNode->data == 1){
                if(ones == NULL){
                    ones = currNode;
                    onesTail = currNode;
                }
                else{
                    onesTail->next = currNode;
                    onesTail = onesTail->next;
                }
            }
            else{
                if(twos == NULL){
                    twos = currNode;
                    twosTail = currNode;
                }
                else{
                    twosTail->next = currNode;
                    twosTail = twosTail->next;
                }
            }
            currNode = currNode->next;
        }
        
        if(zeroes){
            head = zeroes;
            if(ones){
                zeroesTail->next = ones;
                if(twos){
                    onesTail->next = twos;
                    twosTail->next = NULL;
                }
                else onesTail->next = NULL;
            }
            else{
                if(twos){
                    zeroesTail->next = twos;
                    twosTail->next = NULL;
                }
                else{
                    zeroesTail->next = NULL;
                }
            }
        }
        else{
            if(ones){
                head = ones;
                if(twos){
                    onesTail->next = twos;
                    twosTail->next = NULL;
                }
                else{
                    onesTail->next = NULL;
                }
            }
            else{
                head = twos;
                twosTail->next = NULL;
            }
        }
        return head;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends