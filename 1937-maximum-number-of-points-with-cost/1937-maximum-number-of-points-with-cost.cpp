class Solution {
public:
     #define int2 long long
    /*
    Solution giving TLE coz of the so many functions call hence we should go for Bottom up...
    */
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<int2>>dp(m,vector<int2>(n,-1));
        for(int i = 0;i<n;i++){
            dp[m-1][i] = points[m-1][i];
        }
        for(int i = m-2;i>=0;i--){
            vector<int2>left(n);
            vector<int2>right(n);
            //left
            left[0] = dp[i+1][0]+0;
            for(int j = 1;j<n;j++){
                // right
                left[j] = max(left[j-1],dp[i+1][j]+j);
            }
            right[n-1] = dp[i+1][n-1]-(n-1);
            for(int j = n-2;j>=0;j--){
                // left
                right[j] = max(right[j+1],dp[i+1][j]-j);
                // left[j] = dp[m+1][j]+j;
            }
            for(int j = 0;j<n;j++){
                dp[i][j] = points[i][j]+max(left[j]-j,right[j]+j);
            }
            
        }
        for(int i = 0;i<n;i++){
            dp[0][0] = max(dp[0][0],dp[0][i]);
        }
        return dp[0][0];
    }
};