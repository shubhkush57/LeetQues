class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n);
        set<int>z;
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            if(rains[i]>0){
                if(mp.count(rains[i]) == false){
                    ans[i] = -1;
                    mp[rains[i]] = i;
                }
                else{
                    // it is in the map it means that the rains has filled this laske previously and then we have to just drain it before this rains come , for it we will be looking for the zeros..
                    if(z.size()>0){
                        int t = mp[rains[i]];
                        auto it = z.upper_bound(t);
                        if(it != z.end()){
                            ans[i] = -1;
                            mp[rains[i]] = i;
                            ans[*it] = rains[i];
                            z.erase(*it);
                        }
                        else{
                            return {};
                        }
//                         int l = z.back();
                        
//                         if(l>t){
//                             z.pop_back();
//                             ans[i] = -1;
//                             ans[l] = rains[i];
//                         }
//                         else{
//                             return {};
//                         }
                        // it become full again...
                        // we will keep it in the map..
                    }
                    else{
                        //we cannot prevent it..
                        return {};
                    }
                }
            }
            else{
                // we meet the zero..
                z.insert(i);
            }
        }
        // but at the end we have non-empty z then we can fill or refill any index..
        // 
        for(auto it: z){
            ans[it] = 1;
        }
        return ans;
    }
};