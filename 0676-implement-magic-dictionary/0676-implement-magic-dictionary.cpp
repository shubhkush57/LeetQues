class TrieNode{
    public:
    char val;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char data){
        this->val = data;
        this->isTerminal = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
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
        return insertUtil(child,word,i+1);
    }
    bool searchUtil(TrieNode* root,string &word,int i){
        int n = word.size();
        if(root == NULL)return false;
        if(i == n){
            return root->isTerminal;
        }
        char t = word[i];
        return searchUtil(root->children[t-'a'],word,i+1);
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
class MagicDictionary {
public:
    Trie* trieObj = new Trie();
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it: dictionary){
            trieObj->insert(it);
        }
        return;
    }
    
    bool search(string s) {
        int n = s.size();
        for(int i = 0;i<n;i++){
            char t = s[i];
            if(trieObj->prefixSearch(s.substr(0,i))){
                for(char j = 'a';j<='z';j++){
                    if(j != t){
                        s[i] = j;
                        if(trieObj->search(s)){
                            return true;
                        }
                    }
                }
            }
            
            s[i] = t;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */