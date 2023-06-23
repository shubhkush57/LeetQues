class Solution {
public:
    // it takes the solve function and takes 
    bool solve(int mi,int dt,int mask,vector<int>&dp){
        if(dt <= 0){
            //it means next person won it.
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
                // if next person loooses it mens.
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
        // mask bit is one it means it has already been choosen.
        vector<int>dp((1<<mi),-1); // here the space reudtion comes 
        // we have dt depending upon the mask so if we can memeozie only mask 
        // it will be enough.
        int p = 0;//https://leetcode.com/problems/can-i-win/discuss/
        return solve(mi,dt,mask,dp);
    }
};