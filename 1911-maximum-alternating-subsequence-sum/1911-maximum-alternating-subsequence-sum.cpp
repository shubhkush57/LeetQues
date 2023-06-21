class Solution {
public:
    #define int2 long long
    int2 solve(vector<int>&nums,int i,int our,vector<vector<int2>>&dp){
        int n = nums.size();
        if(i == n){
            return 0;
        }
        // we are not going to select this element.
        if(dp[i][our] != -1){
            return dp[i][our];
        }
        int2 not_choose  = solve(nums,i+1,our,dp);
        int2 choose = 0;
        if(our == 0){
            choose = nums[i]+solve(nums,i+1,1,dp);
        }
        else{
            choose = -nums[i]+solve(nums,i+1,0,dp);
        }
        return dp[i][our] = max(choose,not_choose);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        // ai ai+1 ai+2 ai+3 
        // ai is not elmenent of our sequence.
        // ai is our sequence elemnets if is going to be odd then - and if even +
        int n= nums.size();
        vector<vector<int2>>dp(n+1,vector<int2>(2,-1));
        int i = 0;
        int our = 0;
        return solve(nums,i,our,dp);
    }
};