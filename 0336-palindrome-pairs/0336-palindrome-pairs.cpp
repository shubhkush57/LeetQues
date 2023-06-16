class Solution {
public:
    bool isPal(string &s,int i){
        int n = s.size();
        int j = n-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPal1(string &s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        int n = words.size();
        for(int i =0;i<n;i++){
            string s = words[i];
            mp2[s] = i;
            reverse(s.begin(),s.end());
            mp1[s] = i;
        }
        // for(auto it: mp1){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        // cout<<"--------------"<<endl;
        // for(auto it:mp2){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        vector<vector<int>>ans;
        for(int i =0;i<n;i++){
            string re = words[i];
            int siz = re.size();
            if(mp1.count(re) && mp1[re] != i){
                ans.push_back({i,mp1[re]});
            }
            string s = "";
            string v = words[i];
            reverse(v.begin(),v.end());
            for(int j = 1;j<siz;j++){
                s.push_back(re[j-1]);
                // cout<<s<<endl;
                v.pop_back();
                // cout<<v<<endl;
                bool f = isPal(re,j);
                // cout<<f<<endl;
                if(f &&  mp1.count(s) && mp1[s] != i){
                    ans.push_back({i,mp1[s]});
                }
                f = isPal1(s);
                // cout<<f<<endl;
                if(f && mp2.count(v) && mp2[v] != i){
                    ans.push_back({mp2[v],i});
                }
                // cout<<endl;
            }
            string emp = "";
            if(isPal1(words[i]) && mp1.count(emp) && mp1[emp] != i){
                ans.push_back({i,mp1[emp]});
                ans.push_back({mp1[emp],i});
            }
        }
        return ans;
    }
}; 