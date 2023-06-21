class Solution {
public:
    #define int2 long long
    long long countVowels(string word) {
        int2 ans = 0;
        int2 sum = 0;
        int n = word.size();
        for(int i = n-1;i>=0;i--){
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
                sum += (n-i);
            }
            ans += sum;
        }
        return ans;
    }
};