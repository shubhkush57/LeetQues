class Solution {
public:
    #define pp  pair<int,int>
    #define ppp pair<int,pair<int,int>>
    // const int val = 1e5;
    #define int2 long long
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int m = nums.size();
        // int n = nums[0].size();
        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<nums[i].size();j++){
        //         cout<<nums[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        priority_queue<ppp,vector<ppp>,greater<ppp>>pq;
        int maxi = INT_MIN;
        for(int i = 0;i<m;i++){
            maxi = max(nums[i][0],maxi);
            pq.push({nums[i][0],{i,0}}); // row and col
        }
        vector<int> ans = {INT_MIN,INT_MAX};
        while(!pq.empty()){
            // take the minium
            ppp t = pq.top();pq.pop();
            int row = t.second.first;
            int col = t.second.second;
            int val = t.first;
            if((int2)maxi-val < (int2)ans[1] -ans[0]){
                ans = {val,maxi};
            }
            if(col+1 <nums[row].size()){
                maxi = max(maxi,nums[row][col+1]);
                pq.push({nums[row][col+1],{row,col+1}});
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};