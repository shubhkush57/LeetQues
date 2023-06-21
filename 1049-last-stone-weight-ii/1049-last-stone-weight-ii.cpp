class Solution {
public:
    int solve(vector<int>& stones,int i,int sum1,int sum,vector<vector<int>>&dp){
        int n = stones.size();
        if(i == n){
            int sum2 = sum-sum1;
            return abs(sum1-sum2);
        }
        if(dp[i][sum1] != -1){
            return dp[i][sum1];
        }
        return dp[i][sum1] = min(solve(stones,i+1,sum1+stones[i],sum,dp),solve(stones,i+1,sum1,sum,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum2 = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(sum2+1,-1));
        int sum1 = 0;
        int i = 0;
        return solve(stones,i,sum1,sum2,dp);
    }
};