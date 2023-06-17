/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == NULL){
            return "N";
        }
        if(root->val>=0){
            ans.push_back('+');
        }
        else{
            ans.push_back('-');
            root->val = root->val*-1;
        }
        ans += to_string(root->val);
        ans.push_back('(');
        string left = serialize(root->left);
        string right = serialize(root->right);
        int lsiz = left.size()+2;
        int rsiz = right.size()+2;
        ans += to_string(lsiz);
        ans.push_back('(');
        ans += left;
        ans.push_back(')');
        ans += to_string(rsiz);
        ans.push_back('(');
        ans += right;
        ans.push_back(')');
        ans.push_back(')');
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "N"){
            return NULL;
        }
        int val = 0;
        int i = 1;
        int siz = data.size();
        while(i<siz && data[i] != '('){
            val = val *10+(data[i]-'0');
            i++;
        }
        if(data[0] == '-'){
            val = val*-1;
        }
        TreeNode* root = new TreeNode(val);
        i++;
        int lsiz = 0;
        while(i<siz && data[i] != '('){
            lsiz = lsiz *10+(data[i]-'0');
            i++;
        }
        TreeNode* left = deserialize(data.substr(i+1,lsiz-2));
        i = i+lsiz;
        int rsiz = 0;
        while(i<siz && data[i] != '('){
            rsiz = rsiz *10+(data[i]-'0');
            i++;
        }
        TreeNode* right = deserialize(data.substr(i+1,rsiz-2));
        root->left = left;
        root->right = right;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));