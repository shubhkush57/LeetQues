class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        // how many maximum non ovelapping intervalas i can get from it leaving some intervals...
        sort(in.begin(),in.end());
        int n = in.size();
        int ans = 1;
        int prev = in[0][1];
        for(int i = 1;i<n;i++){
            if(in[i][0]>=prev){
                ans++;
                prev = in[i][1];
            }
            else{
                // choose which is going to expand less.
                prev = min(prev,in[i][1]);
            }
        }
        return n-ans;
    }
};