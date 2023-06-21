class Solution {
public:
    double solve(vector<int>&nums,int i,int k,vector<vector<double>>&dp){
        int n = nums.size();
        if(i == n){
            if(k>=0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        double ans = INT_MIN;
        double sum = 0;
        for(int j = i;j<n;j++){
            sum += nums[j];
            double avg = ((double)sum/(j-i+1));
            if(k-1>=0){
                ans = max(ans,avg+solve(nums,j+1,k-1,dp));
            }
            
        }
        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        vector<vector<double>>dp(n+1,vector<double>(k+1,-1));
        double ans = solve(nums,i,k,dp);
        // for(int j = 0;j<=k;j++){
        //     ans = max(ans,solve(nums,i,j));
        // }
        
        return ans;
    }
};