class Solution {
public:
    const int offset = 5000;
    const int ret = -1e4;
    int solve(vector<int>&rods,int i,int diff,vector<vector<int>>&dp){
        int n = rods.size();
        if(i == n){
            if(diff == 0){
                return 0;
            }
            return ret;
        }
        if(dp[i][diff+offset] != -1){
            return dp[i][diff+offset];
        }
        int ans = ret;
        int not_choose = rods[i]+solve(rods,i+1,diff-rods[i],dp);
         ans = max(ans,not_choose);
        int choosen1 =solve(rods,i+1,diff+rods[i],dp);
      ans = max(ans,choosen1);
        int choosen2 = solve(rods,i+1,diff,dp);
        ans = max(ans,choosen2);
        return dp[i][diff+offset] = ans;
    }
    int tallestBillboard(vector<int>& rods) {
       int sum = accumulate(rods.begin(),rods.end(),0);
       int n = rods.size();
       vector<vector<int>>dp(n+1,vector<int>(2*offset+1,-1));
       int ans = solve(rods,0,0,dp);
       return ans;

    }
};