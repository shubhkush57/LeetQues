/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       // fist approach coming in my mind is..
        int siz = 0;
        ListNode* ptr = head;
        while(ptr != NULL){
            siz++;
            ptr = ptr->next;
        }
        ptr = head;
        int re = siz/2;
        while(re--){
            ptr = ptr->next;
        }
        return ptr;
    }
};