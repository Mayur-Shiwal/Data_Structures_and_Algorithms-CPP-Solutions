//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* reverseNode(struct Node *head){
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
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        Node* head1 = reverseNode(head);
        Node* curr = head1;
        vector<int> v;
        while(curr){
            v.push_back(curr->data);
            curr = curr->next;
        }
        int n = v.size();
        for(int i=0;i<n/2;i++) v[i] -= v[n-i-1];
        int cnt = 0;
        Node* curr1 = head1;
        while(cnt < n/2){
            curr1->data = v[cnt++];
            curr1 = curr1->next;
        }
        return head1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends