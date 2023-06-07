class Solution {
public:
    void solve(string &tiles,string &re,set<string>&st){
        
        // take or not take..
        int n = tiles.size();
        for(int i = 0;i<n;i++){
            if(tiles[i] != '.'){
                char t = tiles[i];
                re.push_back(t);
                st.insert(re);
                // cout<<re<<' ';
                tiles[i] = '.';
                solve(tiles,re,st);
                re.pop_back();
                tiles[i] = t;
                
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        // saying all the non empty subsets...
        string re = "";
        set<string>st;
        solve(tiles,re,st);
        return st.size();
    }
};