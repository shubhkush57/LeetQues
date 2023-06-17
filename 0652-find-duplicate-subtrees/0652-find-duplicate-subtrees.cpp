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
    // idea is to conver the each traversal into the string.
    string solve(TreeNode* root,vector<TreeNode*>&ans,unordered_map<string,int>&mp){
        if(root == NULL){
            return "N";
        }
        string s = to_string(root->val);
        s.push_back(',');
        string left = solve(root->left,ans,mp);
        string right = solve(root->right,ans,mp);
        s = s+ left;
        s.push_back(',');
        s = s+ right;
        if(mp[s] == 1){
            ans.push_back(root);
        }
         mp[s]++;  
        return s;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>mp;
        solve(root,ans,mp);
        return ans;
    }
};