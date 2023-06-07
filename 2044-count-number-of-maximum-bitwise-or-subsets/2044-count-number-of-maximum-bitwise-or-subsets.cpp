class Solution {
public:
    void solve(vector<int>&nums,int &ans,int re,int i,int maximum){
        int n = nums.size();
        if(i>=n){
            if(re == maximum){
                ans++;
            }
            // ans = max(ans,re);
            return;
        }
        solve(nums,ans,re,i+1,maximum);
        int t = re | nums[i];
        solve(nums,ans,t,i+1,maximum);
        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // bit wise or 
        int ans = 0;
        int maximum = 0;
        for(auto it: nums){
            maximum = maximum | it;
        }
        int re = 0;
        int i = 0;
        solve(nums,ans,re,i,maximum);
        return ans;
    }
};