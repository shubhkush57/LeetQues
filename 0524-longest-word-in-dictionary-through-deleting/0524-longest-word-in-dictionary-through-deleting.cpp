class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int n = s.size();
        sort(dictionary.begin(),dictionary.end());
        for(int i = 0;i<dictionary.size();i++){
            int k = 0;
            int j = 0;
            int siz = dictionary[i].size();
            while(j<siz && k<n){
                if(dictionary[i][j] == s[k]){
                    j++;
                    k++;
                }
                else{
                    k++;
                }
            }
            if(j == siz){
                if(ans.size()<siz){
                    ans = dictionary[i];
                }
            }
        }
        return ans;
    }
};