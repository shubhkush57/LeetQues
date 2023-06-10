class Solution {
public:
    const int mod = 1e9+7;
    #define int2 long long
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(s[i] == 'L'){
                nums[i] -=d;
            }
            else{
                nums[i] += d;
            }
        }
        sort(nums.begin(),nums.end());
        int2 ans = 0;
        int2 sum = 0;
        for(int i = 0;i<n;i++){
            ans = (ans%mod + (i*(int2)nums[i] -sum)%mod)%mod;
            sum = (sum%mod + nums[i]%mod)%mod;
        }
        return ans%mod;
    }
};