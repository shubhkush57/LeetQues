class Solution {
public:
    const int mod = 1e9+7;
    int solve(int n,int k,int target,vector<vector<int>>&dp){
        if(n == 0){
            if(target == 0){
                return 1;
            }
            return 0;
            
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i = 1;i<=k;i++){
            if(target-i>=0){
                ans = (ans + solve(n-1,k,target-i,dp))%mod;
            }
        }
        return dp[n][target] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        int ans = solve(n,k,target,dp);
        dp[0][0] = 1;
        for(int i = 1;i<= n;i++){
            for(int j = 0;j<=target;j++){
                for(int t = 1;t<=k;t++){
                    if(j-t>=0){
                        dp[i][j]  = (dp[i][j] +  dp[i-1][j-t])%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};