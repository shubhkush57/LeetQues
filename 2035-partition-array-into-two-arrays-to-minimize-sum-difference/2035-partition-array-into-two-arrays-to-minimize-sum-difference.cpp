class Solution {
public:
    #define int2 long long
    #define pp pair<int2,int>
    void solve(vector<int>&nums,int s,int e,int2 sum,int p,vector<pp>&st){
        if(s>e){
            st.push_back({p,sum});
            return;
        }
        solve(nums,s+1,e,sum,p,st);
        solve(nums,s+1,e,sum+nums[s],p+1,st);
        return;
    }
    int minimumDifference(vector<int>& nums) {
        int2 sum = accumulate(nums.begin(),nums.end(),0L);
        vector<pp>l;
        vector<pp>r;
        int n = nums.size();
        int mid = n/2 - 1;
        solve(nums,0,mid,0,0,l);
        solve(nums,mid+1,n-1,0,0,r);
        int2 ans = LLONG_MAX;
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        // vector<pp>l(left.begin(),left.end());
        // for(auto it: l){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        // cout<<endl;
        // vector<pp>r(right.begin(),right.end());
        // for(auto it: r){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        int ls = 0;
        int re = r.size()-1;
        while(ls < l.size() && re>=0){
            while(ls < l.size() && re>=0 && (l[ls].first+ r[re].first <(n/2))){
                // ans = min(ans,abs(sum - 2*(l[ls].second+r[re].second)));
                ls++;
            }
            while(ls< l.size() && re>=0 && (l[ls].first + r[re].first >(n/2))){
                // ans = min(ans,abs(sum - 2*(l[ls].second+r[re].second)));
                re--;
            }
            if(ls< l.size() && re>=0 && (l[ls].first + r[re].first == (n/2))){
                ans = min(ans,abs(sum - 2*(l[ls].second+r[re].second)));
                if(2*(l[ls].second+r[re].second) > sum){
                    re--;
                }
                else{
                    ls++;
                }
            }
        }
        return ans;
        
    }
};