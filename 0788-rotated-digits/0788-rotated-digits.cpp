class Solution {
public:
    int rotatedDigits(int n) {
        // x rotate
        // valid number differnt from x
        // 0 1 8 
        // 2 5
        // 6 9
        // be comes invalid.
        int ans = 0;
        for(int i = 1;i<=n;i++){
            string s = to_string(i);
            bool flag = false;
            for(auto it: s){
                if(it == '3' || it == '4' || it == '7'){
                    flag = false;
                    break;
                }
                if(it =='6' || it == '9' || it == '2' || it == '5'){
                    flag = true;
                }
            }
            if(flag){
                // cout<<s<<endl;
                ans++;
            }
        }
        return ans;
    }
};