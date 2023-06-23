class Solution {
public:
    int dp[40000+5][3];
    int solve(vector<int>&nums,int i,int sum){
        int n = nums.size();
        if(i == n){
            if(sum == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][sum] !=-1){
            return dp[i][sum];
        }
        int ans = 0;
        ans = max(ans,solve(nums,i+1,sum));
        ans = max(ans,nums[i]+ solve(nums,i+1,(sum+(nums[i]%3))%3));
        return dp[i][sum] = ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        int ans = solve(nums,i,0);
        return ans;
    }
};