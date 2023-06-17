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
    int bs(vector<int>&v,int val){
        int start = 0;
        int end = v.size()-1;
        int ans;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(v[mid]>= val){
                ans = mid;
                end = mid-1;
            }
            else{
                start= mid+1;
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*>q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int t = q.size();
            vector<int>v1;
            vector<int>v2;
            while(t--){
                TreeNode* f = q.front();q.pop();
                v1.push_back(f->val);
                v2.push_back(f->val);
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
            }
            sort(v1.begin(),v1.end());
            unordered_map<int,int>mp;
            for(int i = 0;i<v2.size();i++){
                int p = bs(v1,v2[i]);
                if(p == i || mp.count(v2[i])){
                    mp[v2[i]]++;
                    continue;
                }
                else{
                    int nodes = 1;
                    int val = v2[i];
                    mp[val]++;
                    while(mp.count(v2[p]) == false){
                        val = v2[p];
                        p = bs(v1,val);
                        mp[val]++;
                        nodes++;
                    }
                    ans += nodes-1;
                }
                
            }
        }
        return ans;
    }
};