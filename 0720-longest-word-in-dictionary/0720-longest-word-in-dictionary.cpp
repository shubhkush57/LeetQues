class TrieNode{
    public:
    char val;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char data){
        this->val = data;
        this->isTerminal = false;
        for(int i = 0;i<26;i++){
            this->children[i] = NULL;
        }
    }
};
class Trie{
    // it's will be my defined class template for the searching ans inserting the strings.
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('/');
    }
    void insertUtil(TrieNode* root,string& word,int i){
        int n = word.size();
        if(root == NULL){
            return;
        }
        if(i == n){
            root->isTerminal = true;
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
        insertUtil(child,word,i+1);
        return;
    }
    bool searchUtil(TrieNode* root,string &word,int i){
        int n = word.size();
        if(root == NULL)return false;
        if(i == n){
            return root->isTerminal;
        }
        char t = word[i];
        return root->children[t-'a']->isTerminal && searchUtil(root->children[t-'a'],word,i+1);
    }
    bool prefixSearchUtil(TrieNode* root,string &word,int i){
        int n = word.size();
        if(root == NULL){
            return false;
        }
        if(i == n){
            return true;
        }
        char t = word[i];
        return prefixSearchUtil(root->children[t-'a'],word,i+1);
    }
    void insert(string word){
        int i = 0;
        insertUtil(root,word,i);
        return;
    }
    bool search(string word){
        int i = 0;
        return searchUtil(root,word,i);
    }
    bool prefixSearch(string word){
        int i = 0;
        return prefixSearchUtil(root,word,i);
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trieObj = new Trie();
        int n = words.size();
        for(int i = 0;i<n;i++){
            trieObj->insert(words[i]);
        }
        string ans = "";
        sort(words.begin(),words.end());
        for(int i = 0;i<n;i++){
            bool flag = trieObj->search(words[i]);
            if(flag && ans.size()<words[i].size()){
                ans = words[i];
            }
        }
        return ans;
    }
};