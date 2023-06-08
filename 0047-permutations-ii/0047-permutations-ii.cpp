class Solution {
public:
    void solve(set<vector<int>>&st,vector<int>&nums,int i){
        int n = nums.size();
        if(i>=n){
            st.insert(nums);
            return;
        }
        for(int j = i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(st,nums,i+1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // all possible premuations..
        int n = nums.size();
        set<vector<int>>st;
        int i = 0;
        solve(st,nums,i);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};