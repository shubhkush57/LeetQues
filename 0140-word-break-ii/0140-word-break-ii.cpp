class Solution {
public:
    void solve(vector<string>&ans,string &s,unordered_map<string,int>&mp,string &re,int i){
        int n = s.size();
        if(i >=n){
            ans.push_back(re);
            return;
        }
        for(int j = i;j<n;j++){
            string temp = s.substr(i,j-i+1);
            // validity of it...
            if(mp.count(temp)){
                if(j != n-1){
                    re += temp;
                    re += ' ';
                    solve(ans,s,mp,re,j+1);
                    // backtrack...
                    int siz = temp.size()+1;
                    while(siz--){
                        re.pop_back();
                    }
                    
                    
                }
                else{
                    re += temp;
                    solve(ans,s,mp,re,j+1);
                    // backtrack...
                    int siz = temp.size();
                    while(siz--){
                        re.pop_back();
                    }
                }
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string re = ""; // which will be a temp requirements...
        int i = 0; // starting position...
        // suppose we have a word after adding spaces in s to check it's validity we in constant time we will be making wordDict a hashmap..
        unordered_map<string,int>mp;
        for(auto it: wordDict){
            mp[it]++;
        }
        solve(ans,s,mp,re,i);
        return ans;
    }
};