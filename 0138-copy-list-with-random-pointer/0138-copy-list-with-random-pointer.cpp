/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // time complexity will be on(n)
        // and space complexity will be o(n)
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        Node* ptr = new Node(0);
        Node* ans = ptr;
        while(temp != NULL){
            Node* t = new Node(temp->val);
            mp[temp] = t;
            ptr->next = t;
            temp = temp->next;
            ptr = ptr->next;
        }
        temp = head;
        ptr = ans->next;
        while(temp != NULL){
            if(temp->random == NULL){
                ptr->random = NULL;
            }
            else{
                ptr->random = mp[(temp->random)];
            }
            ptr = ptr->next;
            temp = temp->next;
        }
        return ans->next;
    }
};