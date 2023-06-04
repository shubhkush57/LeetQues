class Solution {
public:
    int solve(vector<vector<int>>&mat,int target,int sum,int i,vector<vector<int>>&dp){
        int m = mat.size();
        int n = mat[0].size();
        if(i>=m){
            return abs(target-sum);
        }
        if(dp[sum][i] != -1)return dp[sum][i];
        int ans = INT_MAX;
        if(target-sum>0){
            for(int j = 0;j<n;j++){
                ans = min(ans,solve(mat,target,sum+mat[i][j],i+1,dp));
            }
        }
        else{
            ans = solve(mat,target,sum+mat[i][0],i+1,dp);
        }
        
        return dp[sum][i] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        for(auto &it: mat){
            sort(it.begin(),it.end());
        }
        // minimize the 
        vector<vector<int>>dp(4905,vector<int>(71,-1));
        int ans = solve(mat,target,0,0,dp);
        return ans;
    }
};