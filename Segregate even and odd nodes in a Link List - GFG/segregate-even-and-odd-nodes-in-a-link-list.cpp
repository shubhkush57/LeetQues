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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        // all even numbers appear before than odd.
        Node* even = new Node(0);
        Node* odd = new Node(0);
        Node* joint = odd;
        Node* ans = even;
        while(head != NULL){
            if(head->data % 2 == 0){
                even->next = head;
                even  = even->next;
                
                
            }
            else{
                odd->next = head;
                odd  = odd->next;
                
            }
            Node* t = head->next;
            head->next = NULL;
            head = t;
        }
        //we have to go the end of the 
        Node* evens = ans;
        while(evens->next != NULL){
            evens = evens->next;
        }
        evens->next = joint->next;
        return ans->next;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends