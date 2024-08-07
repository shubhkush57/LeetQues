//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

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

class Solution{
  public:
    //Function to merge K sorted linked list.
    #define pp pair<int,Node*>
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           priority_queue<pp,vector<pp>,greater<pp>>pq; // to find out the minimum.
           Node* temp = new Node(0);
           Node* ans = temp;
           for(int i = 0;i<k;i++){
               if(arr[i] != NULL){
                   pq.push({arr[i]->data,arr[i]});
               }
           }
           while(!pq.empty()){
               pp t = pq.top();pq.pop();
               temp->next = t.second;
               Node* re = t.second->next;
               t.second->next = NULL;
               temp = temp->next;
               // we i have o push it's next elment.
               if(re != NULL){
                   pq.push({re->data,re});
               }
           }
           return ans->next;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends