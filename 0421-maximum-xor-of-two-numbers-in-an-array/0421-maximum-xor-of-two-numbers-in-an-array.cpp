class TrieNode{
public:
    int data;
    TrieNode* left;
    TrieNode* right;
    TrieNode(int val){
        this->data = val;
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
    void insertUtil(TrieNode* root,vector<int>&re,int i){
        int n = re.size();
        if(root == NULL || i == n){
            return;
        }
        int val = re[i];
        TrieNode* child;
        if(val == 1){
            if(root->right != NULL){
                child = root->right;
            }
            else{
                child = new TrieNode(1);
                root->right = child;
            }
        }
        else{
            if(root->left != NULL){
                child = root->left;
            }
            else{
                child = new TrieNode(0);
                root->left = child;
            }
        }
        insertUtil(child,re,i+1);
        return;
    }
    void insert(int val){
        // we have to insert this value in the node.
        vector<int>re(32,0);
        int j = 31;
        for(int i = 0;i<32;i++){
            if((val & (1<<i))>0){
                re[j] = 1;
            }
            j--;
        }
        int i = 0;
        insertUtil(root,re,i);
        return;
    }
    int searchUtil(TrieNode* root,vector<int>&re,int i){
        if(root == NULL || i == 32){
            return 0;
        }
        int ans = 0;
        int val = re[i];
        if(val == 1){
            if(root->left != NULL){
                ans += (1<<(31-i))+searchUtil(root->left,re,i+1);
            }
            else{
                ans += searchUtil(root->right,re,i+1);
            }
        }
        else{
            if(root->right != NULL){
                ans += (1<<(31-i))+searchUtil(root->right,re,i+1);
            }
            else{
                ans += searchUtil(root->left,re,i+1);
            }
        }
        return ans;
    }
    int search(int val){
        vector<int>re(32,0);
        int j = 31;
        for(int i = 0;i<32;i++){
            if((val & (1<<i))>0){
                re[j] = 1;
            }
            j--;
        }
        // int i = 0;
        int ans = searchUtil(root,re,0);
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* trieObj = new Trie();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int t = trieObj->search(nums[i]);
            // cout<<t<<endl;
            ans = max(ans,t);
            trieObj->insert(nums[i]);
        }
        return ans;
    }
};