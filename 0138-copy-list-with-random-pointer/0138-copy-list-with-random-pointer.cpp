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
        // if in the original list i place the new nodes next to the original nodes.
        Node* temp = head;
        
        while(temp != NULL){
            Node* t = new Node(temp->val);
            Node* tnode = temp->next;
            temp->next = t;
            t->next = tnode;
            temp = tnode;
        }
        
        // now i have to assing just the random pointers.
        temp = head;
        while(temp != NULL){
            temp->next->random = (temp->random == NULL)? NULL: temp->random->next;
            temp = temp->next->next;
        }
        // now i have to just make the required list.
        // temp = head;
        // while(temp != NULL){
        //     cout<<temp->val<<' ';temp = temp->next;
        // }
        // cout<<endl;
        Node* ptr = new Node(0);
        Node* ans = ptr;
        Node* re = new Node(0);
        Node* our = re;
        temp = head;
        int count = 0;
        while(temp != NULL){
            Node* t = temp->next;
            if(count%2 == 0){
                // add it to the re;
                re->next = temp;
                re = re->next;
                re->next = NULL;
            }
            else{
                // add it to the ptr;
                ptr->next = temp;
                ptr = ptr->next;
                ptr->next = NULL;
            }
            count++;
            temp = t;
        }
        head = our->next;
        return ans->next;
    }
};