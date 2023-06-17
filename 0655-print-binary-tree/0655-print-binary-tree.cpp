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
    #define ppp pair<TreeNode*,pair<int,int>>
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return 1+max(left,right);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int row = height(root);
        int col = pow(2,row)-1;
        // rowxcol matrix.
        vector<vector<string>>ans(row,vector<string>(col,""));
        queue<ppp>q;
        if(root == NULL){
            return ans;
        }
        q.push({root,{0,(col-1)/2}});
        ans[0][(col-1)/2]  = to_string(root->val);
        while(!q.empty()){
            int t= q.size();
            while(t--){
                ppp f = q.front();q.pop();
                int r = f.second.first;
                int c = f.second.second;
                int re = pow(2,row-r-2);
                if(f.first->left != NULL){
                    ans[r+1][c-re] = to_string(f.first->left->val);
                    q.push({f.first->left,{r+1,c-re}});
                }
                if(f.first->right != NULL){
                    ans[r+1][c+re] = to_string(f.first->right->val);
                    q.push({f.first->right,{r+1,c+re}});
                }
            }
        }
        return ans;
    }
};