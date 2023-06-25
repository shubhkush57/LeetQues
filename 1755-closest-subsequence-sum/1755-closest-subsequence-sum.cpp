class Solution {
public:
    #define int2 long long
    void solve(vector<int>&nums,int s,int e,int2 sum,vector<int2>&left){
        if(s>e){
            left.push_back(sum);
            return;
        }
        solve(nums,s+1,e,sum,left);
        solve(nums,s+1,e,sum+nums[s],left);
        return;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        // if we can solve this problem for smaller n/2
        int mid = n/2;
        vector<int2>left;
        solve(nums,0,mid,0,left);
        vector<int2>right;
        solve(nums,mid+1,n-1,0,right);
        // problem is 2 sum closest to goal
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        int2 ans = LLONG_MAX;
        for(int i = 0;i<left.size();i++){
            ans = min(ans,abs((int2)goal-left[i]));
        }
        for(int i = 0;i<right.size();i++){
            ans = min(ans,abs((int2)goal-right[i]));
        }
        int ls = 0;
        int re = right.size()-1;
        while(ls < left.size() && re >=0){
            ans = min(ans,abs((int2)left[ls]+right[re]-goal));
            if(left[ls]+right[re] > goal){
                re--;
            }
            else{
                ls++;
            }
        }
        
        return ans;
    }
};