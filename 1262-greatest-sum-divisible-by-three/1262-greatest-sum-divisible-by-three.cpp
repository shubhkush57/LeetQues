class Solution {
public:
    int dp[40000+5][3];
    int solve(vector<int>&nums,int i,int rem){
        int n = nums.size();
        if(i >= n){
            if(rem == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][rem] !=-1){
            return dp[i][rem];
        }
        int ans = INT_MIN;
        ans = max(ans,solve(nums,i+1,rem));
        ans = max(ans,nums[i]+ solve(nums,i+1,(rem+nums[i])%3));
        return dp[i][rem] = ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        // sort(nums.begin(),nums.end());
        return solve(nums,0,0);
    }
};