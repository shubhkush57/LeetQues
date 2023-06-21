class Solution {
public:
    int minimumDeletions(string s) {
        // "ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa"
        // so 
        int a = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] =='a'){
                a++;
            }
        }
        int ans = INT_MAX;
        int b = 0;
        int a2 = a;
        int b2 = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == 'b'){
                ans = min(ans,b+a);
                b++;
            }
            else{
                a--;
            }
            if(s[i] == 'a'){
                a2--;
                ans = min(ans,b2+a2);
                
            }
            else{
                b2++;
            }
        }
        
        return ans == INT_MAX?0:ans;
    }
};