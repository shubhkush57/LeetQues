class Solution {
public:
    #define pp pair<int,char>
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // last ant falss out..
        // vector<pp>v;
        int ans = 0;
        for(int i = 0;i<left.size();i++){
            // v.push_back({left[i],'L'});
            ans = max(ans,left[i]);
        }
        for(int i = 0;i<right.size();i++){
            // v.push_back({right[i],'R'});
            ans = max(ans,n-right[i]);
        }
        // sort(v.begin(),v.end());
        // int ans = 0;
        // for(int i = 0;i<v.size();i++){
        //     if(v[i].second == 'R'){
        //         ans = max(ans,n-v[i].first);
        //     }
        //     else{
        //         ans = max(ans,v[i].first);
        //     }
        // }
        return ans;
    }
};