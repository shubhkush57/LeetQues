class Solution {
public:
    #define pp pair<int,int>
    const int m = 1e5;
    int solve(int n,unordered_map<int,int>&dp){
        if(n == 1){
            return 0;
        }
        if(dp.count(n)){
            return dp[n];
        }
        int ans = 0;
        if(n%2 == 0){
            ans = 1+solve(n/2,dp);
        }
        else {
            ans = 1+solve(3*n+1,dp);
        }
        return dp[n] = ans;
    }
    int getKth(int lo, int hi, int k) {
        vector<pp>v;
        // vector<int>dp(m,-1);
        unordered_map<int,int>dp;
        for(int i = lo;i<=hi;i++){
            int t = solve(i,dp);
            v.push_back({t,i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};