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
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           vector<Node*>v;
           // i will be having pointer to each of the node.
           int siz = 0;
           for(int i = 0;i<k;i++){
               if(arr[i]!= NULL){
                   v.push_back(arr[i]);
                   // now want to now it's size.
                   Node* temp = arr[i];
                   int count = 0;
                   while(temp != NULL){
                       count++;
                       temp = temp->next;
                   }
                   siz+= count;
               }
               
           }
           // we are at the begninig.
           Node* ptr = new Node(0);
           Node* ans = ptr;
           while(siz>0){
               // if we have k linked list.
               // find the minimum among all of tem
               int indx;
               int val = INT_MAX;
               for(int i = 0;i<v.size();i++){
                   if(v[i] != NULL){
                       if(val > v[i]->data){
                           indx = i;
                           val = v[i]->data;
                       }
                   }
               }
               Node* nextcoming = v[indx]->next;
               ptr->next = v[indx];
              v[indx]->next = NULL;
               ptr = ptr->next;
               v[indx] = nextcoming;
               siz--;
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