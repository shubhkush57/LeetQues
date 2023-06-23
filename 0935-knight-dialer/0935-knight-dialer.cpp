class Solution {
public:
    const int mod = 1e9+7;
    int dp[5005][10];
    int solve(unordered_map<int,vector<int>>&mp,int n,int i){
        if(n == 0){
            return 1;
        }
        int ans = 0;
        if(dp[n][i] !=-1){
            return dp[n][i];
        }
        for(auto it: mp[i]){
            ans = (ans + solve(mp,n-1,it))%mod;
        }
        return dp[n][i] = ans;
    }
    int knightDialer(int n) {
        unordered_map<int,vector<int>>mp;
        mp[0]= {4,6};
        mp[1] = {6,8};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {0,3,9};
        mp[5] = {};
        mp[6] = {0,1,7};
        mp[7] = {2,6};
        mp[8] = {1,3};
        mp[9] = {2,4};
        // initaill you can palce at any spot..
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = 0;i<=9;i++){
            if(dp[n-1][i] == -1){
                dp[n-1][i] = solve(mp,n-1,i);
            }
            ans = (ans + dp[n-1][i])%mod;
        }
        return ans;
    }
};