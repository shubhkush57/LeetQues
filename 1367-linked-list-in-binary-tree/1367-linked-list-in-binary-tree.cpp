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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checker(TreeNode* root,ListNode* head){
        if(head == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        bool ans = false;
        if(root->val != head->val){
            return ans;
        }
        ans = ans or checker(root->left,head->next);
        ans = ans or checker(root->right,head->next);
        return ans;
    }
    bool solve(TreeNode* root,ListNode* head){
        if(head == NULL){
            return true;
        }  
        if(root == NULL){
            return false;
        }
        // now we will have a root node and we will treat it as a head node of linked list and check whether we have some downward path as linked list if it is return true else false.
        bool ans = checker (root,head);
        ans = ans or solve(root->left,head);
        ans = ans or solve(root->right ,head);
        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(root,head);
    }
};