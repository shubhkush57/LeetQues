class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&re,int val,int k,int n){
        if(val>n){
            if(k == 0){
                ans.push_back(re);
            }
            return;
        }
        //not to choose
        solve(ans,re,val+1,k,n);
        if(k>0){
            re.push_back(val);
            solve(ans,re,val+1,k-1,n);
            re.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        // you have to choose any k numbers...
        vector<vector<int>>ans;
        int val = 1;
        vector<int>re;
        solve(ans,re,val,k,n);
        return ans;
    }
};