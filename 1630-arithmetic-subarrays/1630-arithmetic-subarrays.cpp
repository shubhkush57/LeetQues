class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool>ans(m);
        for(int i = 0;i<m;i++){
            int s = l[i];
            int e = r[i];
            vector<int>temp;
            for(int j = s;j<=e;j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            // for(auto it: temp){
            //     cout<<it<<' ';
            // }
            // cout<<endl;
            if(s == e){
                ans[i] = false;
            }
            else{
                int d = temp[1]-temp[0];
                bool flag = true;
                for(int j = 0;j<temp.size()-1;j++){
                    if(temp[j+1]-temp[j] != d){
                        flag = false;
                        ans[i] = false;
                        break;
                    }
                }
                if(flag == true){
                    ans[i] = true;
                }
            }
        }
        return ans;
    }
};