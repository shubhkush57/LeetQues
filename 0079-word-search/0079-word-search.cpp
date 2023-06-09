class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool solve(vector<vector<char>>& board, string &re,int i,int j,unordered_set<string>&st,unordered_set<string>&st1){
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        for(int k=0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && ny>=0 && ny<n && nx<m && board[nx][ny] != '.'){
                char t = board[nx][ny];
                board[i][j] = '.';
                re.push_back(t);
                if(st1.count(re)){
                    if(st.count(re)){
                        return true;
                    }
                    ans = ans or solve(board,re,nx,ny,st,st1);
                    if(ans == true){
                        return true;
                    }
                }
                re.pop_back();
                board[nx][ny] = t;
            }
        }
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        //it's lenght is 6
        int m = board.size();
        int n = board[0].size();
        // backtracck.....
        unordered_set<string>st;
        st.insert(word);
        unordered_set<string>st1;
        for(int i = 0;i<word.size();i++){
            st1.insert(word.substr(0,i+1));
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                char t = board[i][j];
                board[i][j] = '.';
                string re = "";
                re.push_back(t);
                if(st1.count(re)){
                    if(st.count(re)){
                        return true;
                    }
                    bool ans = solve(board,re,i,j,st,st1);
                    if(ans == true){
                        return true;
                    }
                }
                
                re.pop_back();
                board[i][j] = t;
            }
        }
        return false;
    }
};