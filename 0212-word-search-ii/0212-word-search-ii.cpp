class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void solve(vector<string>&ans,vector<vector<char>>&board,unordered_map<string,int>&mp,string &re,int i,int j,unordered_set<string>&mp1){
        int m = board.size();
        int n = board[0].size();
        for(int k = 0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny] != '.'){
                re.push_back(board[nx][ny]);
                char t = board[nx][ny];
                board[nx][ny] = '.';
                if(mp.count(re)){
                    if(mp1.count(re)){
                        ans.push_back(re);
                        mp1.erase(re);
                        if(mp1.size() == 0){
                            return;
                        }
                    }
                    solve(ans,board,mp,re,nx,ny,mp1);
                }
                board[nx][ny] = t;
                re.pop_back();
            }
        }
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string>ans;
        unordered_map<string,int>mp;
        //wehre we did hashing we need to implement it by trie..
        // Trie* 
        unordered_set<string>mp1;
        for(int i = 0;i<words.size();i++){
            // we can store each 
            mp1.insert(words[i]);
            for(int j = 0;j<words[i].size();j++){
                mp[words[i].substr(0,j+1)]++;
            }
        }
        // for(auto it: mp){
        //     cout<<it.first<<endl;
        // }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                string re = "";
                char t = board[i][j];
                re.push_back(t);
                board[i][j] ='.';
                if(mp.count(re)){
                    if(mp1.count(re)){
                        ans.push_back(re);
                        mp1.erase(re);
                        if(mp1.size() == 0){
                            return ans;
                        }
                    }
                    solve(ans,board,mp,re,i,j,mp1);
                }
                board[i][j] = t;
                re.pop_back();
                
            }
        }
        return ans;
    }
};