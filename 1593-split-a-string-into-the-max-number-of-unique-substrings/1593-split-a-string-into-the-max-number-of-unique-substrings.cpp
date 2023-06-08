class Solution {
public:
    void solve(string &s,set<string>&mp,int &ans,int i){
        int n = s.size();
        if(i>=n){
            int t = mp.size();
            ans = max(ans,t);
            return;
        }
        for(int j = i;j<n;j++){
            string re = s.substr(i,j-i+1);
            if(mp.count(re) == false){
                mp.insert(re);
                solve(s,mp,ans,j+1);
                mp.erase(re);
            }
        }
        return;
    }
    int maxUniqueSplit(string s) {
        set<string>mp;
        int i = 0;
        int n = s.size();
        int ans = 0;
        solve(s,mp,ans,i);
        return ans;
    }
};