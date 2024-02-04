//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node*solve(Node*a,Node*b){
        int carry=0;
        Node*temp=new Node(0);
        Node*curr=temp;
        while(a || b){
            int x = (a==nullptr)? 0 : a->data;
            int y = (b==nullptr)? 0 : b->data;
            if(carry==1){
                x=x-1;
                carry=0;
            }
            if(x-y>=0){
                curr->next = new Node(x-y);
                curr = curr->next;
            }else{
                curr->next = new Node(10+x-y);
                curr = curr->next;
                carry=1;
            }
            a=(a==nullptr)?a:a->next;
            b=(b==nullptr)?b:b->next;
        }
        if(carry)return nullptr;
        return temp->next;
    }
    Node* reverse(Node*head){
        Node*prev=nullptr;
        Node*temp=head;
        Node*curr;
        while(temp){
            curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
         while(head1 && head1->data==0){
            head1=head1->next;
        }
        while(head2 && head2->data==0){
            head2=head2->next;
        }
        if(head1==nullptr && head2==nullptr){
            return new Node(0);
        }
        if(head1==nullptr)return head2;
        if(head2==nullptr)return head1;
        head1=reverse(head1);
        head2=reverse(head2);
        Node*a=head1;
        Node*b=head2;
        
        if(solve(head1,head2)!=nullptr){
            Node*ans=reverse(solve(head1,head2));
             while(ans && ans->data==0){
            ans=ans->next;
            }
            if(ans==nullptr)  return new Node(0);
            return ans;
            
        }
        if(solve(b,a)!=nullptr){
            Node*ans=reverse(solve(b,a));
             while(ans && ans->data==0){
            ans=ans->next;
            }
            if(ans==nullptr)  return new Node(0);
            return ans;
        }
        
    }
};


//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends