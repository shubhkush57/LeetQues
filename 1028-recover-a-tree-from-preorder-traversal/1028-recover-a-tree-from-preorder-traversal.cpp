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
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        TreeNode* root;
        unordered_map<int,TreeNode*>mp;
        int n = traversal.size();
        bool firsttime = true;
        while(i<n){
            int val = 0;
            int count = 0;
            while(i<n && traversal[i] == '-'){
                count++;
                i++;
            }
            while(i<n && traversal[i] != '-'){
                val = val*10+(traversal[i]-'0');
                i++;
            }
            TreeNode* temp = new TreeNode(val);
            if(firsttime){
                firsttime = false;
                root = temp;
            }
            else{
                if(mp[count-1]->left == NULL){
                    mp[count-1]->left= temp;
                }
                else{
                    mp[count-1]->right = temp;
                }
            }
            mp[count] = temp;
        }
        return root;
    }
};