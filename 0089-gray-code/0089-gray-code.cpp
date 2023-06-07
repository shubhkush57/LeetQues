class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans = {0,1};
        while(n>1){
            vector<int>re;
            for(int i = 0;i<ans.size();i++){
                if(i%2 == 0){
                    re.push_back(ans[i]<<1);
                    re.push_back((ans[i]<<1)+1);
                }
                else{
                    
                    re.push_back((ans[i]<<1)+1);
                    re.push_back(ans[i]<<1);
                }
            }
            ans = re;
            n--;
        }
        return ans;
            
    }
};