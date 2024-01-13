//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node* newHead = NULL;
        Node* temp = head_ref;
        if(temp == NULL) return NULL;
        while(temp){
            Node* ptr = newHead, *prev = NULL;
            while(ptr){
                if(ptr->data > temp->data) break;
                prev = ptr;
                ptr = ptr->next;
            }
            if(newHead == NULL){
                newHead = temp;
                temp = temp->next;
                newHead->next = NULL;
            }
            else{
                if(prev == NULL){
                    Node* p1 = temp;
                    temp = temp->next;
                    p1->next = newHead;
                    newHead = p1;
                }
                else{
                    Node* p2 = temp;
                    temp = temp->next;
                    prev->next = p2;
                    p2->next = ptr;
                }
            }
        }
        return newHead;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends