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
        if(i <0){
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
        insertUtil(child,s,i-1);
        return;
    }
    void insert(string s){
        int n = s.size();
        int i = n-1;
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
    bool customUtil(TrieNode* root,string &s,int i){
        int n = s.size();
        if(root == NULL || i<0){
            return false;
        }
        if(root->children[s[i]-'a'] == NULL){
            return false;
        }
        if(root->children[s[i]-'a']->isTerminal == true){
            return true;
        }
        return customUtil(root->children[s[i]-'a'],s,i-1);
    }
    bool custom(string s){
        int n = s.size();
        int i = n-1;
        return customUtil(root,s,i);
    }
    
};
class StreamChecker {
public:
    string s = "";
    // unordered_map<string,int>mp;
    Trie* trieObj;
    int longest_word = 0;
    StreamChecker(vector<string>& words) {
        trieObj = new Trie();
        for(auto it: words){
            // reverse(it.begin(),it.end());
            trieObj->insert(it);
            // mp[it]++;
            longest_word = max(longest_word,(int)(it.size()));
        }
    }
    bool query(char letter) {
        s.push_back(letter);
        if((int)s.size()>longest_word){
            s.erase(s.begin());
        }
        return trieObj->custom(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */