class Solution {
public:
    bool solve(vector<bool>&vis,int &n,vector<int>&leftChild,vector<int>&rightChild,int root,set<int>&rootNodes){
        bool ans = true;
        vis[root] = true; // asuming here every unvisited root comes
        if(leftChild[root] != -1){
            if(vis[leftChild[root]] == true){
                if(rootNodes.count(leftChild[root])){
                    rootNodes.erase(leftChild[root]);
                }
                else{
                    return false;
                }
                
            }
            else{
                ans = ans && solve(vis,n,leftChild,rightChild,leftChild[root],rootNodes);
            }
        }
        
        if(rightChild[root] != -1){
            if(vis[rightChild[root]] == true){
                if(rootNodes.count(rightChild[root])){
                    rootNodes.erase(rightChild[root]);
                }
                else{
                    return false;
                }
            }
            else{
                ans = ans && solve(vis,n,leftChild,rightChild,rightChild[root],rootNodes);
            }
        }
        return ans;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       
        // every node should be visited at least once and if  leftChild[i] or rightChild[i]  is not -1 then they should be visited exactly once.
        vector<bool>vis(n,false);
        //constraint saying it will be in existance.
        set<int>rootNodes;
        
        for(int i = 0;i<n;i++){
            if(vis[i] == false){
                bool temp = solve(vis,n,leftChild,rightChild,i,rootNodes);
                if(temp == false){
                    return false;
                }
                rootNodes.insert(i);
            }
        }
        return rootNodes.size() == 1;
    }
};