class Solution {
public:
    int solve(vector<int>&arr,int s,int e, vector<vector<int>>&dp){
        if(s == e){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int ans = INT_MAX;
        for(int i = s;i<e;i++){
            int l = INT_MIN;
            for(int j = s;j<=i;j++){
                l = max(l,arr[j]);
            }
            int r = INT_MIN;
            for(int j = i+1;j<=e;j++){
                r = max(r,arr[j]);
            }
            ans = min(ans,l*r + solve(arr,s,i,dp)+solve(arr,i+1,e,dp));
        }
        return dp[s][e] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        // sum of it's non leaf..
        // arr contains it's leaf values only.
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int ans = solve(arr,0,n-1,dp);
        return ans;
    }
};