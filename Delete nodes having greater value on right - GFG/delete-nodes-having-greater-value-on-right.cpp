//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverseLL(Node* head){
        Node* ptr = head;
        Node* prev = NULL;
        while(ptr != NULL){
            Node* t = ptr->next;
            ptr->next= prev;
            prev = ptr;
            ptr = t;
            
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node* temp = new Node(0);
        Node* ans = temp;
        // you have to reverse teh temp..
        Node* reptr = head;
        Node* ptr = reverseLL(reptr);
        int maxi = INT_MIN;
        while(ptr != NULL){
            int val = ptr->data;
            if(val >= maxi){
                maxi = val;
                //make new node of maximum.
                Node* t = new Node(maxi);
                temp->next = t;
                temp = temp->next;
            }
            ptr = ptr->next;
        }
        ans = reverseLL(ans->next);
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends