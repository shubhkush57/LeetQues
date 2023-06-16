class TrieNode{
public:
    // 0 will in the left and 1 will be in the right.
    int val;
    TrieNode* left;
    TrieNode* right;
    TrieNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode(-1);
    }
    void insertUtil(TrieNode* root,vector<int>&v,int i){
        if(root == NULL || i<0){
            return;
        }
        int bit = v[i];
        TrieNode* child;
        if(bit == 0){
            if(root->left != NULL){
                child = root->left;
            }
            else{
                child = new TrieNode(0);
                root->left = child;
            }
        }
        else{
            if(root->right != NULL){
                child = root->right;
            }
            else{
                child = new TrieNode(1);
                root->right = child;
            }
        }
        insertUtil(child,v,i-1);
        return;
    }
    void insert(int val){
        // we want to insert this value in the trei.
        vector<int>v(32,0);
        for(int i = 0;i<32;i++){
            if((val & (1<<i)) >0){
                v[i] = 1;
            }
        }
        int i = 31;
        //MSB to LSB.
        insertUtil(root,v,i);
        return;
    }
    int maxXorUtil(TrieNode* root,vector<int>&v,int i){
        if(root == NULL || i<0){
            return 0;
        }
        int ans = 0;
        int bit = v[i];
        if(bit == 0){
            // we should go the left.
            if(root->right != NULL){
                ans = max(ans,(1<<i)+maxXorUtil(root->right,v,i-1));
            }
            else if(root->left != NULL){
                ans = max(ans,maxXorUtil(root->left,v,i-1));
            }
        }
        else{
            if(root->left != NULL){
                ans = max(ans,(1<<i)+maxXorUtil(root->left,v,i-1));
            }
            else if(root->right != NULL){
                ans = max(ans,maxXorUtil(root->right,v,i-1));
            }
            
        }
        return ans;
    }
    int maxXor(int val){
        vector<int>v(32,0);
        for(int i = 0;i<32;i++){
            if((val & (1<<i)) >0){
                v[i] = 1;
            }
        }
        int i = 31;
        return maxXorUtil(root,v,i);
    }
};
class Solution {
public:
    // concept of offline queries.
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = nums.size();
        vector<vector<int>>offline_queries(q);
        for(int i = 0;i<q;i++){
            offline_queries[i] = {queries[i][1],queries[i][0],i};
        }
        Trie* trieObj = new Trie();
        vector<int>ans(q,-1);
        int j = 0;// j point to the nums.
        sort(offline_queries.begin(),offline_queries.end());
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0;i<q;i++){
            
            while(j<n && nums[j]<= offline_queries[i][0]){
                trieObj->insert(nums[j]);
                count++;
                j++;
            }
            if(count != 0){
               int t = trieObj->maxXor(offline_queries[i][1]);
                ans[offline_queries[i][2]] = t;
            }
        }
        return ans;
        
    }
};