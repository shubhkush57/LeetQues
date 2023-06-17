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
    vector<TreeNode*> solve(int n,unordered_map<int,vector<TreeNode*>>&mp){
        vector<TreeNode*>ans;
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            ans.push_back(root);
            return ans;
        }
        if(n == 2){
            return ans;
        }
        if(mp.count(n)){
            return mp[n];
        }
        for(int i = 2;i<=n-1;i++){
            vector<TreeNode*> left = solve(i-1,mp);
            vector<TreeNode*> right = solve(n-i,mp);
            for(auto it1: left){
                for(auto it2: right){
                    TreeNode* root = new TreeNode(0);
                    root->left = it1;
                    root->right = it2;
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // node have 0 or two childrent.
        unordered_map<int,vector<TreeNode*>>mp;
        return solve(n,mp);
    }
};