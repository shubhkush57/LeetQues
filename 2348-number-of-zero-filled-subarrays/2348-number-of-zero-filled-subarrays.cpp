class Solution {
public:
    #define int2 long long
    long long zeroFilledSubarray(vector<int>& nums) {
        int2 ans = 0;
        int n = nums.size();
        int cur = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                cur++;
                ans += (int2)cur;
            }
            else if(nums[i] != 0){
                cur = 0;
            }
        }
        return ans;
    }
};