class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,map<vector<int>,int>&st){
        int n = price.size();
        int ans = 0;
        if(st.count(needs)){
            return st[needs];
        }
        for(int i = 0;i<n;i++){
            ans += (price[i]*needs[i]);
        }
        for(int i = 0;i<special.size();i++){
            // check if you can apply...
            bool flag = true;
            for(int j = 0;j<n;j++){
                if(special[i][j] > needs[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                vector<int>clone = needs;
                for(int j = 0;j<n;j++){
                    clone[j] = clone[j] - special[i][j];
                }
                ans = min(ans,special[i][n]+solve(price,special,clone,st));
                
            }
            
        }
        return st[needs] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        map<vector<int>,int>st;
        int ans = solve(price,special,needs,st);
        return ans;
    }
};