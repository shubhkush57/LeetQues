class Solution {
public:
    int solve(string &s,unordered_map<string,int>&mp,int i,vector<int>&dp){
        int n = s.size();
        if(i == n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j = i;j<n;j++){
            string re = s.substr(i,j-i+1);
            if(mp.count(re)){
                ans = min(ans,solve(s,mp,j+1,dp));
            }
            else{
                ans = min(ans,j-i+1+solve(s,mp,j+1,dp));
            }
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(auto it: dictionary){
            mp[it]++;
        }
        int n = s.size();
        vector<int>dp(n+1,-1);
        int i = 0;
        int ans = solve(s,mp,i,dp);
        return ans;
    }
};