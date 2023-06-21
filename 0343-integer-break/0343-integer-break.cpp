class Solution {
public:
    int solve(int n,int parts,vector<vector<int>>&dp){
        if(n == 1 || n == 0){
            return 1;
        }
        if(dp[n][parts] != -1){
            return dp[n][parts];
        }
        int ans = 1;
        for(int i = 1;i<=n;i++){
            if(parts == 0){
                if(i != n){
                    ans = max(ans,i*solve(n-i,1,dp));
                }
            }
            else{
                ans = max(ans,i*solve(n-i,1,dp));
            }
            
        }
        return dp[n][parts] = ans;
    }
    int integerBreak(int n) {
       
        // n = 5
        // 1*solve(4)
        // 2*solve(3)
        // 3*solve(2);
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(n,0,dp);
            
    }
};