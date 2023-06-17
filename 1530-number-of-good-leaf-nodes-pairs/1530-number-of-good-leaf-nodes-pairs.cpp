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
    vector<int> solve(TreeNode* root,int dis,int &ans){
        if(root == NULL){
            return {};
        }
        if(root->left == NULL && root->right == NULL){
            return {0};
        }
        vector<int>left;
        if(root->left != NULL){
            left = solve(root->left,dis,ans);
        }
        vector<int>right;
        if(root->right != NULL){
            right = solve(root->right,dis,ans);
        }
        vector<int> rev;
        for(int i = 0;i<left.size();i++){
            for(int j = 0;j<right.size();j++){
                if(left[i]+right[j]+2<=dis){
                    ans++;
                }
            }
        }
        for(auto it: right){
            rev.push_back(it+1);
        }
        for(auto it: left){
            rev.push_back(it+1);
        }
        return rev;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root,distance,ans);
        return ans;
    }
};