//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        //if i reverse it..
        Node* temp = head;
        // reverit.
        Node* prev= NULL;
        Node* ptr = head;
        while(ptr != NULL){
            Node* tnode = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tnode;
        }
        // at the end prev will be out hed;
        ptr = prev;
        // i will keep adding 1 and 
        Node* retemp = prev;
        // keep adding the number and reverser it.
        int carry = 1;
        while(retemp != NULL){
            int val = retemp->data+carry;
            if(val == 10){
                carry = 1;
                val = 0;
            }
            else{
                carry = 0;
            }
            retemp->data = val;
            if(retemp->next == NULL){
                if(carry == 1){
                    Node* newnode = new Node(1);
                    retemp->next = newnode;
                    break;
                }
            }
            retemp = retemp->next;
            
        }
        // now do the reverse opeartion again.
        ptr = prev;
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends