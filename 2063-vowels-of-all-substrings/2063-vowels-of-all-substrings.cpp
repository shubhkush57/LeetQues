class Solution {
public:
    #define int2 long long
    long long countVowels(string s) {
        int2 ans = 0;
        int2 sum = 0;
        int n = s.size();
        for(int i = n-1;i>=0;i--){
            if(string("aeiou").find(s[i]) != string::npos){
                sum += (n-i);
            }
            ans += sum;
        }
        return ans;
    }
};