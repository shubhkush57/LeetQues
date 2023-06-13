class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // we will be storing the values of the pairs. and we want our maximum in the range from . 
        // j-x+1 ==k
        //x = j+1-k so x should be greater of equal to this ..
        int n = nums.size();
        priority_queue<pair<int,int>>pq;
        int i = 0;
        int j = 0;
        vector<int>ans;
        for(;j<k;j++){
            pq.push({nums[j],j});
        }
        ans.push_back(pq.top().first);
        while(j<n){
            pq.push({nums[j],j});
            while(!pq.empty() && pq.top().second < (j-k+1)){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            j++;
            i++;
        }
        return ans;
    }
};