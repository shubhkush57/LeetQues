class TrieNode{
  public:
    char val;
    int no;
    TrieNode* children[26];
    TrieNode(char val){
        this->val = val;
        this->no = 0;
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
    void insertUtil(TrieNode* root,string &word,int i){
        if(root == NULL){
            return;
        }
        int n = word.size();
        if(i == n){
            return;
        }
        char t = word[i];
        TrieNode* child;
        if(root->children[t-'a'] == NULL){
            child = new TrieNode(t);
            root->children[t-'a'] = child;
        }
        else{
            child = root->children[t-'a'];
        }
        child->no += 1;
        insertUtil(child,word,i+1);return;
    }
    void insert(string word){
        int i = 0;
        insertUtil(root,word,i);
        return;
    }
    int prefixSearchUtil(TrieNode* root,string &word,int i){
         int n = word.size();
        if(root == NULL ){
            return 0;
        }
        if(i == n){
            return root->no;
        }
        int ans = root->no;
        ans += prefixSearchUtil(root->children[word[i]-'a'],word,i+1);
        return ans;
        
    }
    int prefixSearch(string word){
        int i = 0 ;
        return prefixSearchUtil(root,word,i);
    }
};
class Solution {
public:
    
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie* trieObj = new Trie();
        for(int i = 0;i<n;i++){
            trieObj->insert(words[i]);
        }
        vector<int>ans(n,0);
        for(int i = 0;i<n;i++){
            int temp = trieObj->prefixSearch(words[i]);
            ans[i]= temp;
        }
        return ans;
    }
};