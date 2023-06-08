class Solution {
public:
    bool isPal(string &s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,string &s1,string &s2,int &ans,int i){
        int n = s.size();
        if(i>=n){
            if(isPal(s1) && isPal(s2)){
                int t1 = s1.size();
                int t2 = s2.size();
                ans = max(ans,t1*t2);
            }
            return;
        }
        solve(s,s1,s2,ans,i+1);
        s1.push_back(s[i]);
        solve(s,s1,s2,ans,i+1);
        s1.pop_back();
        s2.push_back(s[i]);
        solve(s,s1,s2,ans,i+1);
        s2.pop_back();
        return;
    }
    int maxProduct(string s) {
        // how to create two disjoint subsequences...
        string s1 = "";
        string s2 = "";
        int ans = 0,i = 0;
        solve(s,s1,s2,ans,i);
        return ans;
    }
};