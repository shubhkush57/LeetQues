class Solution {
public:
    int solve(vector<vector<int>>&pairs,int prev,int i,vector<vector<int>>&dp){
        int n = pairs.size();
        if(i == n){
            return 0;
        }
        if(dp[prev+1][i] != -1){
            return dp[prev+1][i];
        }
        int ans = solve(pairs,prev,i+1,dp);
        
        if(prev == -1){
            ans = max(ans,1 + solve(pairs,i,i+1,dp));
        }
        else{
            if(pairs[i][0] > pairs[prev][1]){
                ans = max(ans,1 + solve(pairs,i,i+1,dp));
            }
            else{
                ans = max(ans,solve(pairs,i,i+1,dp));
            }
        }
        return dp[prev+1][i] = ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        /*
        [li, Ri] [li+1, Ri+1]
        li+1 > Ri // we can attach it in the upcoming chaing.
        if it is less than then it can start it's own chain.
        
        */
        int n = pairs.size();
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        int prev = -1;
        int i = 0;
        return solve(pairs,prev,i,dp);
        
    }
};