class Solution {
public:
    void convertor(int a,vector<int>&b){
        for(int i = 0;i<32;i++){
            if((a &(1<<i)) >0){
                b[i] = 1;
            }
        }
        return;
    }
    int minFlips(int a, int b, int c) {
        vector<int>ab(32,0);
        vector<int>bb(32,0);
        vector<int>cb(32,0);
        convertor(a,ab);
        convertor(b,bb);
        convertor(c,cb);
        int ans = 0;
        for(int i = 0;i<32;i++){
            if(cb[i] == 0){
                if(bb[i] ==1 && ab[i] == 1){
                    ans += 2;
                }
                else if(bb[i] == 1 || ab[i] == 1){
                    ans += 1;
                }
            }
            else{
                if(bb[i] ==0 && ab[i] == 0){
                    ans += 1;
                }
                
            }
        }
        return ans;
    }
};