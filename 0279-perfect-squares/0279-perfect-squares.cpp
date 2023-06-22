class Solution {
public:
    int solve(vector<int>&ps,int n,vector<int>&dp){
        int siz = ps.size();
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = n;
        for(int j = 0;j<siz;j++){
            // we can take any number.
            if(n-ps[j] >=0){
                ans = min(ans,1+ solve(ps,n-ps[j],dp));
            }
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>ps;
        for(int i = 1;i<=n;i++){
            int  root = sqrt(i);
            if(root*root == i){
                ps.push_back(i);
            }
        }
        vector<int>dp(n+1,-1);
        return solve(ps,n,dp);
    }
};