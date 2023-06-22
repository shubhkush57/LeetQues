class Solution {
public:
    // int dp[20][20][2];
    int solve(vector<int>&nums,int start,int end ,vector<vector<int>>&dp){
        int n = nums.size();
        if(start>end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MIN;
       
            ans = max(ans,nums[start]-solve(nums,start+1,end,dp));
            ans = max(ans,nums[end]-solve(nums,start,end-1,dp));
        
        return dp[start][end] = ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // memset(dp,-1,sizeof(dp));
        int start = 0;
        int end = n-1;
        int turn = 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int best = solve(nums,start,end,dp);
        // cout<<best<<endl;
        // for(int start = 0;start<=n;start++){
        //     for(int end = 0;end<=n ;end++){
        //         for(int turn = 0;turn <=1;turn++){
        //             cout<<dp[start][end][turn]<<' ';
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
//         for(int start = n-1;start>=0;start--){
//             for(int end = 1;end<=n;end++){
                    
//                     for(int turn = 0;turn <=1;turn++){
//                         if(start>end){
//                             dp[start][end][turn] = 0;
//                         }
//                         else{
//                             if(turn == 0){
//                                 dp[start][end][turn] = max(dp[start][end][turn],nums[start]-dp[start+1][end][1]);
//                                 dp[start][end][turn] = max(dp[start][end][turn],nums[end]-dp[start][end-1][1]);
//                             }
//                             else{
//                                 dp[start][end][turn] = max(dp[start][end][turn],nums[start]-dp[start+1][end][0]);
//                                 dp[start][end][turn] = max(dp[start][end][turn],nums[end]-dp[start][end-1][0]);
//                             }
                            
//                         }
//                     }
//             }
//         }
        
        return dp[start][end]>= 0;
    }
};