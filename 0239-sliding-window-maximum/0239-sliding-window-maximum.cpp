class MyDeqeue{
  public:
    deque<int>dq;
    void push(int val){
        // it's pushes the elements
        while(!dq.empty() && dq.back()<val){
            dq.pop_back();
        }
        dq.push_back(val);
        return;
    }
    int front(){
        return dq.empty()?-1: dq.front();
    }
    void pop(int val){
        if(dq.front() == val){
            dq.pop_front();
        }
        return;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyDeqeue dq;
        int n = nums.size();
        int i = 0;
        int j = 0;
        vector<int>ans;
        for(;j<k;j++){
            dq.push(nums[j]);
        }
        ans.push_back(dq.front());
        while(j<n){
            dq.push(nums[j]);
            dq.pop(nums[i]);
            ans.push_back(dq.front());
            j++;
            i++;
        }
        return ans;
    }
};