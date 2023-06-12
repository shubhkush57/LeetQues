//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // add two numbeers by linked list..
        // reverse the linked list..
        Node* prev = NULL;
        Node* ptr = first;
        while(ptr != NULL){
            Node* tnode = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tnode;
        }
        Node* ptr1 = prev;
        prev = NULL;
        ptr = second;
        while(ptr != NULL){
            Node* tnode = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tnode;
        }
        Node* ptr2 = prev;
        Node* temp = new Node(0);
        Node* ans = temp;
        int carry = 0;
        while(ptr1 != NULL && ptr2 != NULL){
            int val = ptr1->data + ptr2->data + carry;
            if(val/10 == 0){
                carry = 0;
                Node* nnode = new Node(val);
                temp->next = nnode;
                temp = temp->next;
            }
            else{
                Node* nnode = new Node(val-10);
                temp->next = nnode;
                temp = temp->next;
                carry = val/10;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1 != NULL){
            int val = ptr1->data + carry;
            if(val/10 == 0){
                carry = 0;
                Node* nnode = new Node(val);
                temp->next = nnode;
                temp = temp->next;
            }
            else{
                Node* nnode = new Node(val-10);
                temp->next = nnode;
                temp = temp->next;
                carry = val/10;
            }
            ptr1 = ptr1->next;
            
        }
        while(ptr2 != NULL){
            int val = ptr2->data + carry;
            if(val/10 == 0){
                carry = 0;
                Node* nnode = new Node(val);
                temp->next = nnode;
                temp = temp->next;
            }
            else{
                Node* nnode = new Node(val-10);
                temp->next = nnode;
                temp = temp->next;
                carry = val/10;
            }
            ptr2 = ptr2->next;
            
        }
        if(carry != 0){
            Node* newnode = new Node(carry);
            temp->next = newnode;
            temp = temp->next;
        }
        ptr = ans->next;
        prev = NULL;
        while(ptr != NULL){
            Node* tnode = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tnode;
        }
        return prev;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends