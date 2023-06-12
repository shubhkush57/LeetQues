//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseLL(Node* head){
        // it's reverse the linked list and return the pointer of hte revrse linked list..
        Node* prev = NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* t =temp->next;
            temp->next = prev;
            prev = temp;
            temp= t;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        /* 
        you need to solve it in o(1) space..
        vector<int>v;
        Node* temp = head;
        while(temp != NULL){
            v.push_back(temp->data);temp = temp->next;
        }
        temp = head;
        reverse(v.begin(),v.end());
        int i = 0;
        while(temp != NULL){
            if(temp->data != v[i])return false;
            temp = temp->next; i++;
        }
        return true;
        */
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseLL(slow);
        while(slow != NULL){
            if(head->data != slow->data){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends