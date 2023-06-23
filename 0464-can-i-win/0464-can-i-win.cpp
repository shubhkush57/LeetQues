class Solution {
public:
    // it takes the solve function and takes 
    bool solve(int mi,int dt,int mask,vector<int>&dp){
        if(dt <= 0){
            //it means next person won it don't
            // cout<<mask<<endl;
            return false;
        }
        if(dp[mask] != -1){
            return dp[mask];
        }
        bool ans = false;
        for(int i = 0;i<mi;i++){
            if((mask & (1<<i))>0){
                continue;
            }
            else{
                if(solve(mi,dt-i-1, mask | (1<<i),dp) == false){
                    return dp[mask] = true;
                }
            }
            
        }
        return dp[mask] = ans;
    }
    bool canIWin(int mi, int dt) {
        int mask = 0;
        if(dt<=0)return true;
        if((mi*(mi+1))/2<dt)
        return false;
        // mask bit is one it means 
        vector<int>dp((1<<mi),-1);
        int p = 0;//https://leetcode.com/problems/can-i-win/discuss/
        return solve(mi,dt,mask,dp);
    }
};