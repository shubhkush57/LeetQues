class TrieNode{
    public:
  char val;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char val){
        this->val = val;
        this->isTerminal = false;
        for(int i = 0;i<26;i++){
            this->children[i] = NULL;
        }
    }
};
class Trie{
    public:
  TrieNode* root;
    Trie(){
        root = new TrieNode('/');
    }
    void insertUtil(TrieNode* root,string &s,int i){
        int n = s.size();
        if( root == NULL){
            return;
        }
        if(i ==n){
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        char t = s[i];
        if(root->children[t-'a'] != NULL){
            child = root->children[t-'a'];
        }
        else{
            child = new TrieNode(t);
            root->children[t-'a'] = child;
        }
        insertUtil(child,s,i+1);
        return;
    }
    void insert(string s){
        int i = 0;
        insertUtil(root,s,i);
        return;
    }
    bool searchUtil(TrieNode* root,string &s,int i){
        int n = s.size();
        if(root == NULL){
            return false;
        }
        if(i == n){
            return root->isTerminal;
        }
        return searchUtil(root->children[s[i]-'a'],s,i+1);
    }
    bool search(string s){
        int i = 0;
        return searchUtil(root,s,i);
    }
    
};
class Solution {
public:
    int solve(string &s,Trie* trieObj,int i,vector<int>&dp){
        int n = s.size();
        if(i == n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j = i;j<n;j++){
            string re = s.substr(i,j-i+1);
            if(trieObj->search(re)){
                ans = min(ans,solve(s,trieObj,j+1,dp));
            }
            else{
                ans = min(ans,j-i+1+solve(s,trieObj,j+1,dp));
            }
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie* trieObj = new Trie();
        for(auto it: dictionary){
            trieObj->insert(it);
        }
        int n = s.size();
        vector<int>dp(n+1,-1);
        int i = 0;
        int ans = solve(s,trieObj,i,dp);
        return ans;
    }
};