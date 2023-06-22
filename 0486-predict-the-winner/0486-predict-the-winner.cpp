class Solution {
public:
    int dp[20][20][2];
    int solve(vector<int>&nums,int start,int end ,int turn){
        int n = nums.size();
        if(start>end){
            return 0;
        }
        if(dp[start][end][turn] != -1){
            return dp[start][end][turn];
        }
        int ans = INT_MIN;
        if(turn == 0){
            ans = max(ans,nums[start]-solve(nums,start+1,end,1));
            ans = max(ans,nums[end]-solve(nums,start,end-1,1));
        }
        else{
            ans = max(ans,nums[start]-solve(nums,start+1,end,0));
            ans = max(ans,nums[end]-solve(nums,start,end-1,0));
        }
        return dp[start][end][turn] = ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        memset(dp,-1,sizeof(dp));
        int end = n-1;
        int turn = 0;
        int best = solve(nums,start,end,turn);
        cout<<best<<endl;
        return best >= 0;
    }
};