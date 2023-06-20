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
    #define pp pair<int,int>
    int solve(TreeNode* root,unordered_map<int,int>&mp){
        if(root == NULL){
            return 0;
        }
        
        int l = solve(root->left,mp);
        int r = solve(root->right,mp);
        mp[root->val] = max(l,r);
        return  1+max(l,r);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // height of the each subtree.
        unordered_map<int,int>height;
        solve(root,height);
        vector<int>ans;
        // int q = queries.size();
        // for(auto it: height){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        // level and at each level two elements which have max height.
        queue<TreeNode*>q;
        unordered_map<int,pp>mp;
        q.push(root);
        unordered_map<int,int>l;
        int level = 0;
        while(!q.empty()){
            int t = q.size();
            mp[level] = {0,0};
            
            while(t--){
                TreeNode* f = q.front();q.pop();
                l[f->val] = level;
                if(mp[level].first == 0){
                    mp[level].first = f->val;
                }
                else if(mp[level].second == 0){
                    mp[level].second = f->val;
                    if(height[mp[level].first]< height[mp[level].second]){
                        int temp = mp[level].first;
                        mp[level].first = mp[level].second;
                        mp[level].second = temp;
                    }
                }
                else{
                    if(height[f->val]>=height[mp[level].first]){
                        int temp = mp[level].first;
                        mp[level].first = f->val;
                        mp[level].second = temp;
                    }
                    else if(height[f->val]> height[mp[level].second]){
                        mp[level].second = f->val;
                    }
                }
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
            }
            level++;
        }
        // for(auto it: mp){
        //     cout<<it.first<<"->"<<it.second.first<<' '<<it.second.second<<endl;
        // }
        for(int i = 0;i<queries.size();i++){
            int ele = queries[i];
            int level = l[ele];
            if(mp[level].first != ele){
                if(mp[level].first == 0){
                    ans.push_back(level-1);
                }
                else
                ans.push_back(level+height[mp[level].first]);
            }
            else{
                if(mp[level].second == 0){
                    ans.push_back(level-1);
                }
                else
                ans.push_back(level+height[mp[level].second]);
            }
            
        }
        return ans;
    }
};