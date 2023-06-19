class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int>ans;
        for(auto it: queries){
            int ai = it[0];
            int bi = it[1];
            int dis = 1;
            while(ai != bi){
                if(ai<bi){
                    swap(ai,bi);
                }
                ai = ai/2;
                dis++;
            }
            ans.push_back(dis);
        }
        return ans;
    }
};