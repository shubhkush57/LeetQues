class TrieNode{
  public:
    char val;
    int sum;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char val){
        this->val = val;
        this->sum = 0;
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
    void insertUtil(TrieNode* root,string &word,int i,int num){
         int n = word.size();
        if(root == NULL)return;
        if(i == n){
            root->isTerminal = true;
            return;
        }
        char t = word[i];
        TrieNode* child;
        if(root->children[t-'a'] != NULL){
            child = root->children[t-'a'];
        }
        else{
            child = new TrieNode(t);
            root->children[t-'a'] = child;
        }
        child->sum += num;
        insertUtil(child,word,i+1,num);
        return;
    }
    void insert(string word,int num){
        int i = 0;
        insertUtil(root,word,i,num);
        return;
    }
    int prefixSearchUtil(TrieNode* root,string &word,int i){
        int n = word.size();
        if(root == NULL){
            return 0;
        }
        if(i == n){
            return root->sum;
        }
        
        char t = word[i];
       
        return prefixSearchUtil(root->children[t-'a'],word,i+1);
    }
    int prefixSearch(string word){
        int i = 0;
        return prefixSearchUtil(root,word,i);
    }
    int searchWordUtil(TrieNode* root,string &word,int i){
        int n = word.size();
        if(root == NULL){
            return 0;
        }
        if(i == n){
            if(root->isTerminal == true){
                return root->sum;
            }
            return 0;
        }
        char t = word[i];
        return searchWordUtil(root->children[t-'a'],word,i+1);
    }
    int searchWord(string word){
        int i = 0;
        return searchWordUtil(root,word,i);
    }
};
class MapSum {
public:
    Trie* trieObj;
    unordered_map<string,int>mp;
    MapSum() {
        trieObj = new Trie();
    }
    
    void insert(string key, int val) {
        // int reval = trieObj->searchWord(key);
        int reval = mp[key];
        // cout<<reval<<endl;
        mp[key] = val;
        val = -reval+val;
        
        trieObj->insert(key,val);
        return;
    }
    
    int sum(string prefix) {
        return trieObj->prefixSearch(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */